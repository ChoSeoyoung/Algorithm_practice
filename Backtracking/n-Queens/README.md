# n-Queens Problem
체스의 queen은 대각선과 직선으로 자유롭게 움직일 수 있다. 두 개의 queen이 서로를 공격하지 않도록 하려면 대각선과 직선상에 queen을 함께 배치해서는 안된다. n*n의 체스보드에서 n개의 서로다른 queen들이 서로 공격하지 않는 자리에 어떻게 둘 수 있는가?

즉, backtracking 방식이란 특정 node까지 도달했을 때, 이 node 이후로 더 진행해도 solution이 될 수 없다고 판단되면, parent node로 돌아가서 다시 진행하는 방식이다.