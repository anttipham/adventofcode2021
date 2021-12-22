const fs = require('fs')


const makeArray = (x0, x1, x2) => {
    var arr = []
    for(let i = 0; i < x0; i++) {
        arr[i] = []
        for(let j = 0; j < x1; j++) {
            arr[i][j] = []
            for(let k = 0; k < x2; k++) {
                arr[i][j][k] = 0
            }
        }
    }
    return arr;
}


const MAX_WIN_SCORE=40  // 30 is max score for winning
const MIN_WIN_SCORE=21
const MAX_PLACE=11  // 10 is max place
const MAX_THROWS=12  // idk, but 11 should be enough

const input = fs.readFileSync("input").toString()
startPlaces = input.split("\r\n").map((a) => Number(a[28]))  // prefix is 28 characters long

const play = (startPlace) => {
    const timeUniverse = makeArray(MAX_THROWS, MAX_WIN_SCORE, MAX_PLACE)
    timeUniverse[0][0][startPlace] = 1
    // console.log(scoreUniverse)

    for (let throws=0; throws<MAX_THROWS; throws++) {
        for (let score=0; score<MIN_WIN_SCORE; score++) {
            for (let place=1; place<MAX_PLACE; place++) {
                const copies = timeUniverse[throws][score][place]
                if (!copies) continue
                // 3 times throw die
                for (let i=1; i<=3; i++) {
                    for (let j=1; j<=3; j++) {
                        for (let k=1; k<=3; k++) {
                            let nextPlace = place + i + j + k
                            while (nextPlace > 10) nextPlace -= 10

                            // console.log(throws, score, nextPlace)
                            timeUniverse[throws+1][score+nextPlace][nextPlace] += copies
                        }
                    }
                }
            }
        }
    }
    return timeUniverse.map((scoreUniverse) =>
        scoreUniverse.map((placeUniverse) =>
            placeUniverse.reduce((prev, cur) => prev + cur)
        )
    )
}

const calcWins = (scores0, scores1) => {
    let wins0 = 0
    let losts1 = 0
    for (let score=MIN_WIN_SCORE; score<MAX_WIN_SCORE; score++) {
        wins0 += scores0[score]
    }
    for (let score=0; score<21; score++) {
        losts1 += scores1[score]
    }
    return wins0 * losts1
}

const main = () => {
    const universe0 = play(startPlaces[0])
    const universe1 = play(startPlaces[1])
    // console.log(universe0)

    let wins0 = 0
    let wins1 = 0
    for (let throws=2; throws<MAX_THROWS; throws++) {
        // 1st player wins and he has 1 more throw
        wins0 += calcWins(universe0[throws], universe1[throws-1])
        // 2nd player wins and both players have equal throws
        wins1 += calcWins(universe1[throws], universe0[throws])
    }
    console.log(wins0)
    console.log(wins1)
}


main()