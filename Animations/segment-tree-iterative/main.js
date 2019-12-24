function parent(i) {
	return i >> 1;
}

function leftChild(i) {
	return i << 1;
}

function rightChild(i) {
	return i << 1 | 1;
}

elements = [8,7,3,9,5,1,2,4,6,0]
let N = elements.length

nodes = [];
edges = [];

let st = new Array(2 * N);
for (let i = 0; i < 2 * N; i++) st[i] = 0;
for (let i = N; i < 2 * N; i++) {
	st[i] = elements[i - N];
	nodes.push({id: i, label: `${i}, ${elements[i - N]}`});
}

for (let i = N - 1; i >= 0; i--) {
	st[i] = st[leftChild(i)] + st[rightChild(i)];
	nodes.push({id: i, label: `${i}, ${st[i]}`});
	if (i) {
		edges.push({from: leftChild(i), to: i});
	}
	edges.push({from: rightChild(i), to: i});
}

var data = {
  nodes: new vis.DataSet(nodes),
  edges: new vis.DataSet(edges)
};

var options = {
  	layout: {
    	hierarchical: {
      	direction: "DU",
      	sortMethod: "directed"
    	}
	},
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
    	}
    },
    edges: {
    	width: 8,
    	background: {
    		enabled: true,
    		color: "#6AA84F"
    	}
    }
};

let container = document.getElementById("SegmentTreeCanvas");

network = new vis.Network(container, data, options);