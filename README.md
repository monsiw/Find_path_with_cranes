# Find Path With Cranes
There are N cranes arranged in a line. The K-th crane is located at distance P[K] from the beggining of the road and its arm length is equal to A[K]. The cranes can't change their places. There is a package, initially located at position B, that has to be moved by the cranes to position E. The K-th crane can pick up the package only if the distance between its position and the package position is less than equal to A[K] (the package is within arm range from the crane's position).
A package can be moved by a crane to an arbitrary position within the crane's arm reach (between P[K]-A[K] and P[K]+A[K] for the K-th crane). 
For example, if P[K]=5 and A[K]=3, the K-th crane can move packages anywhere between positions 2 and 8, including both of the boudries.<br/><br/>
<img src="https://github.com/monsiw/Find_path_with_cranes/blob/main/img.PNG" width="400" height="200" /><br/><br/>
Determine whether it is possible to move the package from position B to position E using some (possibly all) of the cranes.
