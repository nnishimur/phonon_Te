#include <Eigen/Dense>
#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;

struct force_constant_model {
    // Matrices used to construct the dynamical matrix
    Eigen::Matrix3d v, v01, v12, v0, v1, v2;
    // Projection matrices
    Eigen::MatrixXcd P0, P1, P2;
    // Dynamical matrix
    Eigen::MatrixXcd VL1;
    double tz;

    force_constant_model(double K1, double K2, double K3, double c,
                         double theta) {
        double K22 =
            K2 * cos(theta) * cos(theta) + K3 * sin(theta) * sin(theta);
        double K33 =
            K3 * cos(theta) * cos(theta) + K2 * sin(theta) * sin(theta);
        double dK = (K3 - K2) * sin(theta) * cos(theta);
        tz = c / 3.0;
        v << K1, 0, 0, 0, K22, -dK, 0, -dK, K33;
        Eigen::Matrix3d C3;
        C3 << -0.5, -0.5 * sqrt(3), 0, 0.5 * sqrt(3), -0.5, 0, 0, 0, 1;
        v01 = C3.transpose() * v * C3;
        v12 = C3 * v * C3.transpose();
        v0 = v01 + v;
        v1 = v12 + v01;
        v2 = v + v12;
        complex<double> zeta = complex(-0.5, 0.5 * sqrt(3));
        // Eigenvectors of T (Translation)
        Eigen::Matrix3cd u;
        u << 1.0 / sqrt(3), 1.0 / sqrt(3), 1.0 / sqrt(3), 1.0 / sqrt(3),
            zeta / sqrt(3), conj(zeta) / sqrt(3), 1.0 / sqrt(3),
            conj(zeta) / sqrt(3), zeta / sqrt(3);
        // Eigenvectors of C_3 (3-fold rotation)
        Eigen::Matrix3cd w;
        w << 0.0, 1.0 / sqrt(2), 1.0 / sqrt(2), 0.0,
            complex(0.0, -1.0 / sqrt(2)), complex(0.0, 1.0 / sqrt(2)), 1.0, 0.0,
            0.0;
        // Projection matrix to m=0 eigenspace
        P0 = Eigen::MatrixXcd::Zero(9, 3);
        for(int i = 0; i < 9; i++)
            P0(i, 0) = u(i / 3, 0) * w(i % 3, 0);
        for(int i = 0; i < 9; i++)
            P0(i, 1) = u(i / 3, 1) * w(i % 3, 2);
        for(int i = 0; i < 9; i++)
            P0(i, 2) = u(i / 3, 2) * w(i % 3, 1);
        // Projection matrix to m=1 eigenspace
        P1 = Eigen::MatrixXcd::Zero(9, 3);
        for(int i = 0; i < 9; i++)
            P1(i, 0) = u(i / 3, 0) * w(i % 3, 1);
        for(int i = 0; i < 9; i++)
            P1(i, 1) = u(i / 3, 1) * w(i % 3, 0);
        for(int i = 0; i < 9; i++)
            P1(i, 2) = u(i / 3, 2) * w(i % 3, 2);
        // Projection matrix to m=-1 eigenspace
        P2 = Eigen::MatrixXcd::Zero(9, 3);
        for(int i = 0; i < 9; i++)
            P2(i, 0) = u(i / 3, 0) * w(i % 3, 2);
        for(int i = 0; i < 9; i++)
            P2(i, 1) = u(i / 3, 1) * w(i % 3, 1);
        for(int i = 0; i < 9; i++)
            P2(i, 2) = u(i / 3, 2) * w(i % 3, 0);

        VL1 = Eigen::MatrixXcd::Zero(9, 9);
    }

    void make_dynamical_matrix(double kz) {
        complex<double> gamma = exp(complex(0.0, 1.0) * kz * tz);
        VL1 = Eigen::MatrixXcd::Zero(9, 9);
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                VL1(i, j) = v0(i, j);
                VL1(i, j + 3) = -gamma * v01(i, j);
                VL1(i, j + 6) = -conj(gamma) * v(i, j);
                VL1(i + 3, j) = -conj(gamma) * v01(i, j);
                VL1(i + 3, j + 3) = v1(i, j);
                VL1(i + 3, j + 6) = -gamma * v12(i, j);
                VL1(i + 6, j) = -gamma * v(i, j);
                VL1(i + 6, j + 3) = -conj(gamma) * v12(i, j);
                VL1(i + 6, j + 6) = v2(i, j);
            }
        }
    }

    vector<double> solve(double kz) {
        make_dynamical_matrix(kz);
        vector<double> freq(9);
        // m=0
        Eigen::SelfAdjointEigenSolver<Eigen::MatrixXcd> eigensolver0(
            P0.adjoint() * VL1 * P0);
        if(eigensolver0.info() != Eigen::Success)
            abort();
        for(int i = 0; i < 3; i++)
            freq[i] = sqrt(eigensolver0.eigenvalues()[i]);
        // m=1
        Eigen::SelfAdjointEigenSolver<Eigen::MatrixXcd> eigensolver1(
            P1.adjoint() * VL1 * P1);
        if(eigensolver1.info() != Eigen::Success)
            abort();
        for(int i = 0; i < 3; i++)
            freq[i + 3] = sqrt(eigensolver1.eigenvalues()[i]);
        // m=-1
        Eigen::SelfAdjointEigenSolver<Eigen::MatrixXcd> eigensolver2(
            P2.adjoint() * VL1 * P2);
        if(eigensolver2.info() != Eigen::Success)
            abort();
        for(int i = 0; i < 3; i++)
            freq[i + 6] = sqrt(eigensolver2.eigenvalues()[i]);

        return freq;
    }
};

int main() {
    // Parameters
    // Force constants
    double K1 = 3.0 / 2.0;
    double K2 = 3.0 / 6.0;
    double K3 = 3.0;
    // Lattice constant
    double c = 1.0;
    // Angle defined in Fig. 1(b) of the paper
    double theta = 0.3 * M_PI;
    // Number of divisions of the Brillouin zone
    int Nz = 100;

    force_constant_model model(K1, K2, K3, c, theta);

    ofstream outputfile("phonon.txt");
    outputfile
        << "#kz, 3 eigenvalues(m=0), 3 eigenvalues(m=1), 3 eigenvalues(m=-1)"
        << endl;
    double dkz = M_PI / c / (double)Nz;

    for(int m = -Nz; m <= Nz; m++) {
        double kz = m * dkz;
        vector<double> freq = model.solve(kz);
        outputfile << kz;
        for(int i = 0; i < 9; i++)
            outputfile << ", " << freq[i];

        outputfile << endl;
    }
    outputfile.close();
}