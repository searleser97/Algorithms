function countSetBits(n) {
  let cnt = 0;
  while (n) {
    cnt++;
    n -= (n & -n);
  }
  return cnt;
}

function build() {
  bit = document.getElementById("data").value.split(" ").map(Number);
  bit.unshift("0");
  let numbersLength = 5;

  nodes = [];
  edges = [];

  for (let i = 1; i < bit.length; i++) {
    let j = i + (i & -i);
    if (j < bit.length) bit[j] += bit[i];
  }

  for (let i = 0; i < bit.length; i++) {
    let from  = 0, to = 0;
    from = i - (i & -i) + 1;
    if (i == 0) from = 0;
    nodes.push({id: i, label:
      `${i}: ${(i).toString(2).padStart(numbersLength, 0)}\n` +
      `S[${from}, ${i}] = ${bit[i]}\n`
    });
  }

  for (let i = 1; i < bit.length; i++) {
    let dad = i - (i & -i);
    edges.push({from: i, to: dad});
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
}

aux = []

let index = 0;

function nextStep() {
  if (index == 0) {
    aux = document.getElementById("data").value.split(" ").map(Number);
  }
  if (index == aux.length) {
    alert("FIN");
    index = 0;
    return;
  }
  document.getElementById("data").value = aux.slice(0, index).join(" ");
  build();
  index++;
}


let input = document.getElementById("data")
input.addEventListener("keyup", function(event) {
    if (event.keyCode === 13) {
        event.preventDefault();
        build();
    }
});

build();