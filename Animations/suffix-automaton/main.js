class State {
    len = 0;
    link = 0;
    next = new Map();
    isclone = 0;
}

class SuffixAutomaton {
    st = [];
    sz = 0;
    last = 0;

    constructor(s) {
        for (let i = 0; i < 2 * s.length; i++) {
            this.st.push(new State());
        }
        this.st[0].len = 0;
        this.st[0].link = -1;
        this.sz = 1;
        this.last = 0;
        for (let c of s) this.add(c);
    }

    add(c) {
        let p = this.last, cur = this.sz++;
        this.st[cur].len = this.st[p].len + 1;
        while (p !== -1 && !this.st[p].next.has(c)) {
            this.st[p].next.set(c, cur);
            p = this.st[p].link;
        }
        if (p === -1) this.st[cur].link = 0;
        else {
            let q = this.st[p].next.get(c);
            console.log(q, p);
            if (this.st[p].len + 1 === this.st[q].len) {
                this.st[cur].link = q;
            } else {
                let clone = this.sz++;
                this.st[clone].isclone = 1;
                this.st[clone].len = this.st[p].len + 1;
                this.st[clone].next = new Map(this.st[q].next)
                this.st[clone].link = this.st[q].link;
                while (p !== -1 && this.st[p].next.get(c) === q) {
                    this.st[p].next.set(c, clone);
                    p = this.st[p].link;
                }
                this.st[cur].link = clone;
                this.st[q].link = clone;
            }
        }
        this.last = cur;
    }
}

function build() {
    let str = document.getElementById("data").value;

    let sa = new SuffixAutomaton(str)

    let terminals = []

    let p = sa.last;

    while (p) {
        terminals.push(p);
        p = sa.st[p].link;
    }

    console.log("last:", sa.last)
    console.log("states:", sa.st)
    console.log("terminals:", terminals)

    let nodesUsed = new Set();
    let nodes = [];
    let edges = [];

    // ---- Reverse Graph

    let reversed = new Array(sa.st.length)
    for (let i = 0; i < reversed.length; i++) {
        reversed[i] = new State();
    }

    for (let i = 0; i < sa.st.length; i++) {
        for (let [c, to] of sa.st[i].next.entries()) {
            if (!reversed[to].next.has(c)) {
                reversed[to].next.set(c, []);
            }
            let newSet = reversed[to].next.get(c);
            newSet.push(i);
            reversed[to].next.set(c, newSet);
        }
    }

    // ---- End reverse graph

    let dp = new Array(sa.st.length)
    for (let i = 0; i < dp.length; i++) {
        dp[i] = { len: 0, str: "" };
    }

    function labeling(node) {
        let transitions = reversed[node].next;
        let curMax = 0;
        if (dp[node].len) {
            return dp[node].len;
        }
        for (let [c, multiTo] of transitions.entries()) {
            for (let to of multiTo) {
                edges.push({ from: to, to: node, label: c, color: "#545454" })
                let ans = labeling(to);
                if (ans > curMax) {
                    curMax = ans;
                    dp[node].str = dp[to].str + c;
                }
            }
        }
        nodes.push({ id: node, label: dp[node].str + "\nid: " + node + "\nisClone: " + sa.st[node].isclone + "\nlen: " + sa.st[node].len  });
        if (node) {
            edges.push({ from: node, to: sa.st[node].link, color: "red", dashes: true });
        }
        return dp[node].len = curMax + 1;
    }

    labeling(sa.last, "")

    

    var data = {
        nodes: new vis.DataSet(nodes),
        edges: new vis.DataSet(edges)
    };

    data.nodes.update({id: 0, color: {background: "orange"}, label: "Start"});

    for (let n of terminals) {
        data.nodes.update({id: n, color: {background: "green"}});
    }

    var options = {
        nodes: {
            shape: "circle",
            borderWidth: 3,
            color: {
                border: "#6AA84F",
                background: "#3C78D8"
            },
            font: {
                color: "white",
                size: 15,
                strokeWidth: 1,
                strokeColor: "white"
            },
            physics: false
        },
        edges: {
            width: 2,
            font: {
                color: "black",
                size: 25,
                strokeWidth: 3,
                strokeColor: "white"
            },
            arrows: {
                to: {
                    enabled: true,
                    type: "arrow"
                }
            }
        }
    };

    let container = document.getElementById("SegmentTreeCanvas");

    network = new vis.Network(container, data, options);
}

let input = document.getElementById("data")

input.addEventListener("keyup", function(event) {
    if (event.keyCode === 13) {
        event.preventDefault();
        build();
    }
});

build();