library(gamair)
library(tibble)


data(chicago)
chicago = as_tibble(chicago)

nch = nrow(chicago)
tmpSmooth = numeric(nch)

system("ls *.c")
system("R CMD SHLIB expSmooth.c")
dyn.load("expSmooth.so")
is.loaded("expSmooth")


.Call("expSmooth", chicago$tmpd, tmpSmooth, nch, 0.5)

plot(chicago$tmpd[1:1000], col = "grey", ylab = "Temp")
lines(tmpSmooth[1:1000], col = 2)



