
# Compile and load C function
system("ls *.c")
system("R CMD SHLIB rickerSimul.c")
dyn.load("rickerSimul.so")
is.loaded("rickerSimul")

# Set variables
nburn <- 100
n <- 50
y0_true <- 1
sig_true <- 0.1
r_true <- 10

# Call C function
Ntrue = .Call("rickerSimul", as.integer(n), as.integer(nburn), as.integer(r_true), y0_true)

yobs <- y0_true * exp(rnorm(n, 0, sig_true))

plot(yobs, type = 'b')
