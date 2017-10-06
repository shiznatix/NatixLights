module.exports = {
	// 20 x 7

	OFF: `
		_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
		_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
		_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
		_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
		_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
		_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
		_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	`,

	CAUTION: [
		`
			_ _ _ _ _ _ _ _ _ r r _ _ _ _ _ _ _ _ _
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
			_ _ _ r r _ _ _ _ _ _ _ _ _ _ r r _ _ _
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
		`,
		`
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
			_ _ _ r r _ _ _ _ _ _ _ _ _ _ r r _ _ _
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
			_ _ _ _ _ _ _ _ _ r r _ _ _ _ _ _ _ _ _
		`,
		`
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
			_ _ _ r r _ _ _ _ _ _ _ _ _ _ r r _ _ _
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
			_ _ _ _ _ _ _ _ _ r r _ _ _ _ _ _ _ _ _
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
		`,
		`
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
			_ _ _ r r _ _ _ _ _ _ _ _ _ _ r r _ _ _
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
			_ _ _ _ _ _ _ _ _ r r _ _ _ _ _ _ _ _ _
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
		`,
		`
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
			_ _ _ r r _ _ _ _ _ _ _ _ _ _ r r _ _ _
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
			_ _ _ _ _ _ _ _ _ r r _ _ _ _ _ _ _ _ _
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
		`,
		`
			_ _ _ r r _ _ _ _ _ _ _ _ _ _ r r _ _ _
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
			_ _ _ _ _ _ _ _ _ r r _ _ _ _ _ _ _ _ _
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
		`,
		`
			_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
			_ _ _ _ _ _ _ _ _ r r _ _ _ _ _ _ _ _ _
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
			_ _ _ r r _ _ _ _ r r _ _ _ _ r r _ _ _
			_ _ _ r r _ _ _ _ _ _ _ _ _ _ r r _ _ _
		`,
	],

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

	// STOP: `
	// 	r r r _ _ _ _ _ _ _ _ _ _ _ _ _ _ r r r
	// 	r r r _ _ _ _ _ _ r r _ _ _ _ _ _ r r r
	// 	r r r _ r r _ _ _ r r _ _ _ r r _ r r r
	// 	r r r _ r r _ _ _ r r _ _ _ r r _ r r r
	// 	r r r _ r r _ _ _ r r _ _ _ r r _ r r r
	// 	r r r _ r r _ _ _ r r _ _ _ r r _ r r r
	// 	r r r _ r r _ _ _ _ _ _ _ _ r r _ r r r
	// `,
	// STOP: `
	// 	_ _ r r _ _ r r _ _ _ _ r r _ _ r r _ _
	// 	_ r r _ _ r r _ _ _ _ _ _ r r _ _ r r _
	// 	r r _ _ r r _ _ _ r r _ _ _ r r _ _ r r
	// 	r _ _ r r _ _ _ r r r r _ _ _ r r _ _ r
	// 	r r _ _ r r _ _ _ r r _ _ _ r r _ _ r r
	// 	_ r r _ _ r r _ _ _ _ _ _ r r _ _ r r _
	// 	_ _ r r _ _ r r _ _ _ _ r r _ _ r r _ _
	// `,
	STOP: `
		_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
		_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
		r r r r r r r r r r r r r r r r r r r r
		r r r r r r r r r r r r r r r r r r r r
		r r r r r r r r r r r r r r r r r r r r
		_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
		_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	`,

	HAPPY: `
		g g _ _ g g _ g g g g g g _ g g _ _ g g
		g g _ _ g g _ g g _ _ g g _ g g _ _ g g
		g g g g g g _ g g g g g g _ g g g g g g
		_ _ g g _ _ _ g g g g g g _ _ _ g g _ _
		_ _ g g _ _ _ g g _ _ g g _ _ _ g g _ _
		_ _ g g _ _ _ g g _ _ g g _ _ _ g g _ _
		_ _ g g _ _ _ g g _ _ g g _ _ _ g g _ _
	`,
	
	RAINBOW: `
		r r r r r r r r r r r r r r r r r r r r
		o o o o o o o o o o o o o o o o o o o o
		y y y y y y y y y y y y y y y y y y y y
		g g g g g g g g g g g g g g g g g g g g
		b b b b b b b b b b b b b b b b b b b b
		p p p p p p p p p p p p p p p p p p p p
		w w w w w w w w w w w w w w w w w w w w
	`,

	ESTONIA_CROSS_FLAG: `
		b b b b b _ w _ b b b b b b b b b b b b
		b b b b b _ w _ b b b b b b b b b b b b
		_ _ _ _ _ _ w _ _ _ _ _ _ _ _ _ _ _ _ _
		w w w w w w w w w w w w w w w w w w w w
		_ _ _ _ _ _ w _ _ _ _ _ _ _ _ _ _ _ _ _
		b b b b b _ w _ b b b b b b b b b b b b
		b b b b b _ w _ b b b b b b b b b b b b
	`,

	USA_FLAG: `
		b w b w b w b b r r r r r r r r r r r r
		b b w b w b w b w w w w w w w w w w w w
		b w b w b w b b r r r r r r r r r r r r
		b b w b w b w b w w w w w w w w w w w w
		r r r r r r r r r r r r r r r r r r r r
		w w w w w w w w w w w w w w w w w w w w
		r r r r r r r r r r r r r r r r r r r r
	`,
}