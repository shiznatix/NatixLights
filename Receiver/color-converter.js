const scene = `
b b b b b 0 w 0 b b b b b b b b b b b b
b b b b b 0 w 0 b b b b b b b b b b b b
0 0 0 0 0 0 w 0 0 0 0 0 0 0 0 0 0 0 0 0
w w w w w w w w w w w w w w w w w w w w
0 0 0 0 0 0 w 0 0 0 0 0 0 0 0 0 0 0 0 0
b b b b b 0 w 0 b b b b b b b b b b b b
b b b b b 0 w 0 b b b b b b b b b b b b
`;
const colorMap = {
	b: 'COLOR_BLUE',
	r: 'COLOR_RED',
	w: 'COLOR_WHITE',
	'0': 'COLOR_OFF',
};
let output = [];
let lineCounter = 0;

scene.split('\n').forEach((line) => {
	line = line.trim();

	if ('' === line) {
		return;
	}

	if (1 === Math.abs(lineCounter % 2)) {
		line = line.split('').reverse().join('');
	}

	Object.keys(colorMap).forEach(function(key) {
		const replace = colorMap[key];
	
		//console.log(`${replace} ${key}`);
		line = line.split(key).join(`${replace},`);
	});

	output.push(line);

	lineCounter++;
});

output.forEach((line) => {
	console.log(line);
});