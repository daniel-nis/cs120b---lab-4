tests = [ {'description': 'PINA: 0x04 => PORTB: 0x00',
    'steps': [ {'inputs': [('PINA',0x04)], 'iterations': 1 } ],
    'expected': [('PORTB',0x00)],
    },

	{'description': 'PINA: 0x00, PINA: 0x04, PINA: 0x00, PINA: 0x04, PINA: 0x00, PINA: 0x02, PINA:0x00 => PORTB: 0x01',
    'steps': [{'inputs': [('PINA',0x00)], 'iterations': 1 },
 	{'inputs': [('PINA',0x04)], 'iterations': 1 },
 	{'inputs': [('PINA',0x00)], 'iterations': 1 },
 	{'inputs': [('PINA',0x04)], 'iterations': 1 },
 	{'inputs': [('PINA',0x00)], 'iterations': 1 },
	{'inputs': [('PINA',0x02)], 'iterations': 1 },
        {'inputs': [('PINA',0x00)], 'iterations': 1 },
 	],
    'expected': [('PORTB',0x01)],
    },

	]

#watch = [State]

