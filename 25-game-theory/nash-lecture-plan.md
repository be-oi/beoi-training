# Mini-lecture on "real" game theory
Note: These are not lecture notes; **this is not meant to be understandable**. Please don't read this. This is meant to be a lecture plan for (probably) me to give the lecture easily later.

See [nash-lectures-sample.pdf] (_also_ not meant to be understandable).

## Is it better to go first or go last?
- consider following game
    - matrix `A` in `R^{n*m}`
    - row player chooses `i` in `[n]`
    - column player chooses `j` in `[m]`
    - outcome is A_{ij}, so
        - row player wants to maximize A_{ij} (row player = "maximizing" player)
        - column player wants to minimize A_{ij} (column player = "minimizing" player)
- imagine that row player first chooses the i publicly, _then_ column player chooses j
    - this means computing `max_i min_j A_{ij}`
    - compare that with column player going first (i.e. `min_j max_i A_{ij}`)
    - is it better to go first or last?
- take example of penalty in soccer:
    - row player is player shooting the penalty, can choose to shoot left or right
    - column player is goal keeper, can shoot to protect left or right
    - notice that it's better to go last
- is it _always_ better (or at least as good) to go last?
- prove it

## Simultaneous?
- what if the players make the decisions simultaneously?
    - if shooter knows keeper is planning to jump left, shooter will decide to shoot right
    - but then keeper, knowing that the shooter will be thinking this, decides to protect right
    - shooter thinks ahead and decides to shoot left in the end
    - keeper adapts to jump left
    - etc. loops!
- no _equilibrium_:
    - Nash equilibrium: combination of choices where no agent is incentivizes to change their mind (assuming no one _else_ changes theirs)
    - here, doesn't exist!

## Mixed strategies
- now, what if the strategies are allowed to be random? does it solve the issue?
- say row player chooses `i` with probability `p_i`
    - and column player `j` w.p. `q_j`
    - then outcome is `p^tAq`
- does it solve the cycling?
    - take example where shooter and keeper both do 50/50
- does it solve dependence on order of decision?
    - it does here!
- in fact, generally true by von Neumann's minimax theorem
    - and this proves that equilibrium exists (why? is that really true? **to prove before next lecture**)
