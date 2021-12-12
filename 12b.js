const fs = require('fs')

// const input = fs.readFileSync("in").toString()
const input = fs.readFileSync("input").toString()
const graph = new Map()

input
    .split("\r\n")
    .map((inputLine) => inputLine.split("-"))
    .forEach((caveLink) => {
        const [a, b] = caveLink
        if (!graph[a]) {
            graph[a] = []
        }
        if (!graph[b]) {
            graph[b] = []
        }
        graph[a].push(b)
        graph[b].push(a)
    })


const isLowerCase = (s) => s === s.toLowerCase()
let count = 0
let extra = ""
let checked = {}
checked["start"] = true
let debug = []

const dfs = (node) => {
    debug.push(node)
    if (node === "end") {
        count++
        // console.log(debug)
        debug.pop()
        return
    }

    for (const next of graph[node]) {
        if (next === "start") continue

        if (checked[next]) {
            if (!extra) {
                extra = next
                dfs(next)
                extra = ""
            }
            continue
        }

        if (isLowerCase(next)) {
            checked[next] = true
            dfs(next)
            checked[next] = false
        } else {
            dfs(next)
        }
    }
    debug.pop()
}
try {
    dfs("start")
} finally {
    console.log(count)
}
