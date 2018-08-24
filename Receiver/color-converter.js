const fs = require('fs');
const animations = require('./animations.js');

let outputLines = [
	"//animations",
	`const int ANIM_FRAMES = ${animations.CAUTION.length};`,
	"const int PIXEL_COUNT = 243;",
	"",
	"const char _ = '_';",
	"const char r = 'r';",
	"const char o = 'o';",
	"const char y = 'y';",
	"const char g = 'g';",
	"const char b = 'b';",
	"const char p = 'p';",
	"const char w = 'w';",
	"",
];

function parseScene(scene) {
	let output = [];
	let lineCounter = 0;
	let onCount = 0;
	
	scene.split('\n').forEach((line) => {
		line = line.trim();

		if ('' === line) {
			return;
		}

		if (1 === Math.abs(lineCounter % 2)) {
			line = line.split('').reverse().join('');
		}

		const colors = line.split(' ');

		colors.forEach((color) => {
			if ('_' !== color) {
				onCount++;
			}
		});

		line = colors.join(',');
		line += ',';

		output.push(line);

		lineCounter++;
	});

	const lastLineIndex = (output.length - 1);
	const lastLine = output[lastLineIndex];
	
	output[lastLineIndex] = lastLine.substring(0, lastLine.length - 1);
	output.unshift(`// on count: ${onCount}`);

	return output;
}

function parseAnim(imageName, anim) {
	if (Array.isArray(anim)) {
		outputLines.push(`const char IMAGE_${imageName}[ANIM_FRAMES][PIXEL_COUNT] = {`);

		anim.forEach((frame) => {
			outputLines.push('\t{');

			parseScene(frame).forEach((line) => {
				outputLines.push(`\t\t${line}`);
			});

			outputLines.push('\t},');
		});
	} else {
		outputLines.push(`const char IMAGE_${imageName}[PIXEL_COUNT] = {`);

		parseScene(anim).forEach((line) => {
			outputLines.push(`\t${line}`);
		});
	}

	outputLines.push('};');
}

Object.keys(animations).forEach((key) => {
	parseAnim(key, animations[key]);
});

fs.writeFile('./Animations.h', outputLines.join('\n'), (error) => {
	if (error) {
		console.log(error);
		return;
	}

	console.log('Animations.h file written');
});
