const animations = require('./animations.js');

const scene = animations.happy;
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

	line = line.split(' ').join(', ');
	line += ',';

	output.push(line);

	lineCounter++;
});

const lastLineIndex = (output.length - 1);
const lastLine = output[lastLineIndex];

output[lastLineIndex] = lastLine.substring(0, lastLine.length - 1);

output.forEach((line) => {
	console.log(line);
});