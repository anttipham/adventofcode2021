import itertools

die = itertools.cycle(range(1,101))

place = [
    int(input().removeprefix("Player 1 starting position: ")),
    int(input().removeprefix("Player 2 starting position: "))
]
score = [0, 0]

def play(player: int):
    for _ in range(3):
        place[player] += next(die)
    while place[player] > 10:
        place[player] -= 10
    score[player] += place[player]


def main():
    die_thrown = 0
    turn = 0
    while score[0] < 1000 and score[1] < 1000:
        play(turn)
        die_thrown += 3
        turn ^= 1
    print(min(score), die_thrown)
    print(min(score) * die_thrown)


main()