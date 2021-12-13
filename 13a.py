from collections import namedtuple

Dot = namedtuple("Dot", ["x", "y"])
# from dataclasses import dataclass

# @dataclass(order=True, eq=True)
# class Dot:
#     x: int
#     y: int


def fold_left(x: int, dots: set[Dot]):
    new_dots: set[Dot] = set()

    for dot in dots:
        if dot.x > x:
            dot = Dot(x - abs(dot.x - x), dot.y)
        new_dots.add(dot)
    return new_dots


def fold_up(y: int, dots: set[Dot]):
    new_dots: set[Dot] = set()

    for dot in dots:
        if dot.y > y:
            dot = Dot(dot.x, y - abs(dot.y - y))
        new_dots.add(dot)
    return new_dots


def count_dots(dots: set[Dot]):
    dots.sort()

    new_dots = []
    prev_dot = 0
    for dot in dots[1:]:
        if dot == prev_dot:
            continue
        new_dots.append(dot)

    return new_dots


def main():
    dots: set[Dot] = set()
    while line := input():
        dot = line.split(",")
        x, y = map(int, dot)
        dots.add(Dot(x, y))
    # print(f"{dots=}")

    foldsUp: list[int] = []
    foldsLeft: list[int] = []
    try:
        while line := input():
            # print(line)
            line = line.removeprefix("fold along ")
            if line.startswith("y="):
                y = int(line.removeprefix("y="))
                foldsUp.append(y)
            elif line.startswith("x="):
                x = int(line.removeprefix("x="))
                foldsLeft.append(x)
    except EOFError:
        pass
    # print(f"{foldsUp=}")
    # print(f"{foldsLeft=}")

    print(f"{dots=}")
    print(len(dots))

    # dots = fold_up(7, dots)
    dots = fold_left(655, dots)

    print(f"{dots=}")
    print(len(dots))


if __name__ == "__main__":
    main()