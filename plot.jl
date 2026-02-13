using Plots

function main()
    filename = "phonon.txt"

    kzs = Float64[]
    Es = Vector{Float64}[[] for i = 1:9]
    fp = open(filename, "r")
    readline(fp)
    for line in eachline(fp)
        l = parse.(Float64, split(line, ",", keepempty=false))
        push!(kzs, l[1])
        for i = 1:9
            push!(Es[i], l[i+1])
        end
    end
    close(fp)

    for i = 1:3
        plot!(kzs, Es[i], xlabel="k_z", ylabel="ω", xlims=(-π, π), ylims=(0, 3), legend=:topleft, label=(i == 1 ? "m = 0" : ""), lc=:black)
    end
    for i = 1:3
        plot!(kzs, Es[i+3], label=(i == 1 ? "m = 1" : ""), lc=:red)
    end
    for i = 1:3
        plot!(kzs, Es[i+6], label=(i == 1 ? "m = -1" : ""), lc=:blue)
    end
    savefig("phonon.png")
end

main()