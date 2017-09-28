module.exports = {
	// 20 x 7

	// OFF: `
	// 	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	// 	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	// 	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	// 	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	// 	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	// 	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	// 	_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	// `,

	CAUTION: [
		`
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
			_ y r r r _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
			r y _ _ _ r _ _ _ _ _ _ _ _ _ _ _ _ _ _
			r _ y y _ r _ _ _ _ _ _ _ _ _ _ _ _ _ _
			r _ _ _ y r _ _ _ _ _ _ _ _ _ _ _ _ _ _
			_ r r r y _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
		`,
		`
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
			_ _ r y r r _ _ _ _ _ _ _ _ _ _ _ _ _ _
			_ r _ y _ _ r _ _ _ _ _ _ _ _ _ _ _ _ _
			_ r _ y y _ r _ _ _ _ _ _ _ _ _ _ _ _ _
			_ r _ _ y _ r _ _ _ _ _ _ _ _ _ _ _ _ _
			_ _ r r y r _ _ _ _ _ _ _ _ _ _ _ _ _ _
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
		`,
		`
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
			_ _ _ r r y r _ _ _ _ _ _ _ _ _ _ _ _ _
			_ _ r _ _ y _ r _ _ _ _ _ _ _ _ _ _ _ _
			_ _ r _ y y _ r _ _ _ _ _ _ _ _ _ _ _ _
			_ _ r _ y _ _ r _ _ _ _ _ _ _ _ _ _ _ _
			_ _ _ r y r r _ _ _ _ _ _ _ _ _ _ _ _ _
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
		`,
		`
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
			_ _ _ _ r r r y _ _ _ _ _ _ _ _ _ _ _ _
			_ _ _ r _ _ _ y r _ _ _ _ _ _ _ _ _ _ _
			_ _ _ r _ y y _ r _ _ _ _ _ _ _ _ _ _ _
			_ _ _ r y _ _ _ r _ _ _ _ _ _ _ _ _ _ _
			_ _ _ _ y r r r _ _ _ _ _ _ _ _ _ _ _ _
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
		`,
		`
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
			_ _ _ _ _ r r r r _ _ _ _ _ _ _ _ _ _ _
			_ _ _ _ r _ _ _ y y _ _ _ _ _ _ _ _ _ _
			_ _ _ _ r _ y y _ r _ _ _ _ _ _ _ _ _ _
			_ _ _ _ y y _ _ _ r _ _ _ _ _ _ _ _ _ _
			_ _ _ _ _ r r r r _ _ _ _ _ _ _ _ _ _ _
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
		`,
		`
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
			_ _ _ _ _ _ r r r r _ _ _ _ _ _ _ _ _ _
			_ _ _ _ _ r _ _ _ _ r _ _ _ _ _ _ _ _ _
			_ _ _ _ _ y y y y y y _ _ _ _ _ _ _ _ _
			_ _ _ _ _ r _ _ _ _ r _ _ _ _ _ _ _ _ _
			_ _ _ _ _ _ r r r r _ _ _ _ _ _ _ _ _ _
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
		`,
		`
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
			_ _ _ _ _ _ _ r r r r _ _ _ _ _ _ _ _ _
			_ _ _ _ _ _ y y _ _ _ r _ _ _ _ _ _ _ _
			_ _ _ _ _ _ r _ y y _ r _ _ _ _ _ _ _ _
			_ _ _ _ _ _ r _ _ _ y y _ _ _ _ _ _ _ _
			_ _ _ _ _ _ _ r r r r _ _ _ _ _ _ _ _ _
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
		`,
		`
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
			_ _ _ _ _ _ _ _ y r r r _ _ _ _ _ _ _ _
			_ _ _ _ _ _ _ r y _ _ _ r _ _ _ _ _ _ _
			_ _ _ _ _ _ _ r _ y y _ r _ _ _ _ _ _ _
			_ _ _ _ _ _ _ r _ _ _ y r _ _ _ _ _ _ _
			_ _ _ _ _ _ _ _ r r r y _ _ _ _ _ _ _ _
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
		`,
		`
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
			_ _ _ _ _ _ _ _ _ r y r r _ _ _ _ _ _ _
			_ _ _ _ _ _ _ _ r _ y _ _ r _ _ _ _ _ _
			_ _ _ _ _ _ _ _ r _ y y _ r _ _ _ _ _ _
			_ _ _ _ _ _ _ _ r _ _ y _ r _ _ _ _ _ _
			_ _ _ _ _ _ _ _ _ r r y r _ _ _ _ _ _ _
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
		`,
		`
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
			_ _ _ _ _ _ _ _ _ _ r r y r _ _ _ _ _ _
			_ _ _ _ _ _ _ _ _ r _ _ y _ r _ _ _ _ _
			_ _ _ _ _ _ _ _ _ r _ y y _ r _ _ _ _ _
			_ _ _ _ _ _ _ _ _ r _ y _ _ r _ _ _ _ _
			_ _ _ _ _ _ _ _ _ _ r y r r _ _ _ _ _ _
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
		`,
		`
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
			_ _ _ _ _ _ _ _ _ _ _ r r r y _ _ _ _ _
			_ _ _ _ _ _ _ _ _ _ r _ _ _ y r _ _ _ _
			_ _ _ _ _ _ _ _ _ _ r _ y y _ r _ _ _ _
			_ _ _ _ _ _ _ _ _ _ r y _ _ _ r _ _ _ _
			_ _ _ _ _ _ _ _ _ _ _ y r r r _ _ _ _ _
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
		`,
		`
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
			_ _ _ _ _ _ _ _ _ _ _ _ r r r r _ _ _ _
			_ _ _ _ _ _ _ _ _ _ _ r _ _ _ y y _ _ _
			_ _ _ _ _ _ _ _ _ _ _ r _ y y _ r _ _ _
			_ _ _ _ _ _ _ _ _ _ _ y y _ _ _ r _ _ _
			_ _ _ _ _ _ _ _ _ _ _ _ r r r r _ _ _ _
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
		`,
		`
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
			_ _ _ _ _ _ _ _ _ _ _ _ _ r r r r _ _ _
			_ _ _ _ _ _ _ _ _ _ _ _ r _ _ _ _ r _ _
			_ _ _ _ _ _ _ _ _ _ _ _ y y y y y y _ _
			_ _ _ _ _ _ _ _ _ _ _ _ r _ _ _ _ r _ _
			_ _ _ _ _ _ _ _ _ _ _ _ _ r r r r _ _ _
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
		`,
		`
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ r r r r _ _
			_ _ _ _ _ _ _ _ _ _ _ _ _ y y _ _ _ r _
			_ _ _ _ _ _ _ _ _ _ _ _ _ r _ y y _ r _
			_ _ _ _ _ _ _ _ _ _ _ _ _ r _ _ _ y y _
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ r r r r _ _
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
		`,
		`
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ y r r r _
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ r y _ _ _ r
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ r _ y y _ r
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ r _ _ _ y r
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ r r r y _
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
		`,
	],

	// caution: [
	// 	`
	// 		y y y y y y y y y y y y y y y y y y y y
	// 		y _ _ y _ _ y y y y y y y y _ _ y _ _ y
	// 		y _ _ y _ _ y _ _ _ _ _ _ y _ _ y _ _ y
	// 		y _ _ y _ _ y _ _ y y _ _ y _ _ y _ _ y
	// 		y _ _ y _ _ y _ _ _ _ _ _ y _ _ y _ _ y
	// 		y _ _ y _ _ y y y y y y y y _ _ y _ _ y
	// 		y y y y y y y y y y y y y y y y y y y y
	// 	`,
	// 	`
	// 		y y y y y y y y y y y y y y y y y y y y
	// 		y _ _ y _ _ y y y y y y y y _ _ y _ _ y
	// 		y _ _ y _ _ y _ _ _ _ _ _ y _ _ y _ _ y
	// 		y _ _ y _ _ y _ _ r r _ _ y _ _ y _ _ y
	// 		y _ _ y _ _ y _ _ _ _ _ _ y _ _ y _ _ y
	// 		y _ _ y _ _ y y y y y y y y _ _ y _ _ y
	// 		y y y y y y y y y y y y y y y y y y y y
	// 	`,
	// 	`
	// 		y y y y y y y y y y y y y y y y y y y y
	// 		y _ _ y _ _ r r r r r r r r _ _ y _ _ y
	// 		y _ _ y _ _ r _ _ _ _ _ _ r _ _ y _ _ y
	// 		y _ _ y _ _ r _ _ r r _ _ r _ _ y _ _ y
	// 		y _ _ y _ _ r _ _ _ _ _ _ r _ _ y _ _ y
	// 		y _ _ y _ _ r r r r r r r r _ _ y _ _ y
	// 		y y y y y y y y y y y y y y y y y y y y
	// 	`,
	// 	`
	// 		y y y r r r r r r r r r r r r r r y y y
	// 		y _ _ r _ _ r r r r r r r r _ _ r _ _ y
	// 		y _ _ r _ _ r _ _ _ _ _ _ r _ _ r _ _ y
	// 		y _ _ r _ _ r _ _ r r _ _ r _ _ r _ _ y
	// 		y _ _ r _ _ r _ _ _ _ _ _ r _ _ r _ _ y
	// 		y _ _ r _ _ r r r r r r r r _ _ r _ _ y
	// 		y y y r r r r r r r r r r r r r r y y y
	// 	`,
	// 	`
	// 		r r r r r r r r r r r r r r r r r r r r
	// 		r _ _ r _ _ r r r r r r r r _ _ r _ _ r
	// 		r _ _ r _ _ r _ _ _ _ _ _ r _ _ r _ _ r
	// 		r _ _ r _ _ r _ _ r r _ _ r _ _ r _ _ r
	// 		r _ _ r _ _ r _ _ _ _ _ _ r _ _ r _ _ r
	// 		r _ _ r _ _ r r r r r r r r _ _ r _ _ r
	// 		r r r r r r r r r r r r r r r r r r r r
	// 	`,
	// ],

	LEFT_TURN: `
		_ _ _ _ _ _ b b _ _ _ _ _ _ _ _ _ _ _ _
		_ _ _ _ b b b b _ _ _ _ _ _ _ _ _ _ _ _
		_ _ b b b b b b b b b b b b b b b b b b
		b b b b b b b b b b b b b b b b b b b b
		_ _ b b b b b b b b b b b b b b b b b b
		_ _ _ _ b b b b _ _ _ _ _ _ _ _ _ _ _ _
		_ _ _ _ _ _ b b _ _ _ _ _ _ _ _ _ _ _ _
	`,

	STOP_LEFT_TURN: `
		_ _ _ _ _ _ r r _ _ _ _ _ _ _ _ _ _ _ _
		_ _ _ _ r r r r _ _ _ _ _ _ _ _ _ _ _ _
		_ _ r r r r r r r r r r r r r r r r r r
		r r r r r r r r r r r r r r r r r r r r
		_ _ r r r r r r r r r r r r r r r r r r
		_ _ _ _ r r r r _ _ _ _ _ _ _ _ _ _ _ _
		_ _ _ _ _ _ r r _ _ _ _ _ _ _ _ _ _ _ _
	`,

	RIGHT_TURN: `
		_ _ _ _ _ _ _ _ _ _ _ _ b b _ _ _ _ _ _
		_ _ _ _ _ _ _ _ _ _ _ _ b b b b _ _ _ _
		b b b b b b b b b b b b b b b b b b _ _
		b b b b b b b b b b b b b b b b b b b b
		b b b b b b b b b b b b b b b b b b _ _
		_ _ _ _ _ _ _ _ _ _ _ _ b b b b _ _ _ _
		_ _ _ _ _ _ _ _ _ _ _ _ b b _ _ _ _ _ _
	`,

	STOP_RIGHT_TURN: `
		_ _ _ _ _ _ _ _ _ _ _ _ r r _ _ _ _ _ _
		_ _ _ _ _ _ _ _ _ _ _ _ r r r r _ _ _ _
		r r r r r r r r r r r r r r r r r r _ _
		r r r r r r r r r r r r r r r r r r r r
		r r r r r r r r r r r r r r r r r r _ _
		_ _ _ _ _ _ _ _ _ _ _ _ r r r r _ _ _ _
		_ _ _ _ _ _ _ _ _ _ _ _ r r _ _ _ _ _ _
	`,

	STOP: `
		y y y y y y y y y y y y y y y y y y y y
		r r r r _ r r r r r _ r r r r _ r r r r
		r _ _ _ _ _ _ r _ _ _ r _ _ r _ r _ _ r
		r r r r _ _ _ r _ _ _ r _ _ r _ r r r r
		_ _ _ r _ _ _ r _ _ _ r _ _ r _ r _ _ _
		r r r r _ _ _ r _ _ _ r r r r _ r _ _ _
		y y y y y y y y y y y y y y y y y y y y
	`,

	HAPPY: `
		_ g _ _ _ g _ g g g g g _ g _ _ _ g _ _
		_ g _ _ _ g _ g _ _ _ g _ g _ _ _ g _ _
		_ _ g _ g _ _ g _ _ _ g _ _ g _ g _ _ _
		_ _ _ g _ _ _ g g g g g _ _ _ g _ _ _ _
		_ _ _ g _ _ _ g _ _ _ g _ _ _ g _ _ _ _
		_ _ _ g _ _ _ g _ _ _ g _ _ _ g _ _ _ _
		_ _ _ g _ _ _ g _ _ _ g _ _ _ g _ _ _ _
	`,
	
	// RAINBOW: `
	// 	r r r r r r r r r r r r r r r r r r r r
	// 	o o o o o o o o o o o o o o o o o o o o
	// 	y y y y y y y y y y y y y y y y y y y y
	// 	g g g g g g g g g g g g g g g g g g g g
	// 	b b b b b b b b b b b b b b b b b b b b
	// 	p p p p p p p p p p p p p p p p p p p p
	// 	w w w w w w w w w w w w w w w w w w w w
	// `,

	// ESTONIA_CROSS: `
	// 	b b b b b _ w _ b b b b b b b b b b b b
	// 	b b b b b _ w _ b b b b b b b b b b b b
	// 	_ _ _ _ _ _ w _ _ _ _ _ _ _ _ _ _ _ _ _
	// 	w w w w w w w w w w w w w w w w w w w w
	// 	_ _ _ _ _ _ w _ _ _ _ _ _ _ _ _ _ _ _ _
	// 	b b b b b _ w _ b b b b b b b b b b b b
	// 	b b b b b _ w _ b b b b b b b b b b b b
	// `,

	// USA: `
	// 	b w b w b w b b r r r r r r r r r r r r
	// 	b b w b w b w b w w w w w w w w w w w w
	// 	b w b w b w b b r r r r r r r r r r r r
	// 	b b w b w b w b w w w w w w w w w w w w
	// 	r r r r r r r r r r r r r r r r r r r r
	// 	w w w w w w w w w w w w w w w w w w w w
	// 	r r r r r r r r r r r r r r r r r r r r
	// `,
}