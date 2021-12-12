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
console.log(graph)


let count = 0

const isLowerCase = (s) => s === s.toLowerCase()

const dfs = (node, checked = new Map()) => {
    if (node === "end") {
        count++
        return
    }

    for (const next of graph[node]) {
        if (checked[next]) continue
        if (next !== "end" && isLowerCase(next)) {
            checked[next] = true
            dfs(next, checked)
            checked[next] = false
        } else {
            dfs(next, checked)
        }
        // console.log(1, node, next)
        // console.log(-1, node, next)
    }
}
dfs("start", { start: true })

console.log(count)