tests = [ {'description': 'PINA: 0x00, 0x01, 0x01, 0x00, 0x01 => 0x01.',
    'steps': [ {'inputs': [('PINA',0x00)], 'iterations': 5 },
	{'inputs': [('PINA',0x01)], 'iterations': 5 },
	{'inputs': [('PINA',0x01)], 'iterations': 5 },
	{'inputs': [('PINA',0x00)], 'iterations': 5 },
	{'inputs': [('PINA',0x01)], 'iterations': 5 }, ],
    'expected': [('PORTB',0x01)],
    },
    ]

watch = [State]

