tests = [ 
    {'description': 'PressPA0  => PORTC: 0x08 ',
    'steps': [ {'inputs': [('PINA',0xFF)], 'iterations': 1 },
               {'inputs': [('PINA',0xFE)], 'iterations': 1 },
               {'inputs': [('PINA',0xFF)], 'iterations': 1 },
               {'inputs': [('PINA',0xFE)], 'iterations': 1 },
               {'inputs': [('PINA',0xFF)], 'iterations': 1 },
               {'inputs': [('PINA',0xFE)], 'iterations': 1 },
               {'inputs': [('PINA',0xFF)], 'iterations': 1 },
               {'inputs': [('PINA',0xFE)], 'iterations': 1 },
               {'inputs': [('PINA',0xFF)], 'iterations': 1 },
               {'inputs': [('PINA',0xFE)], 'iterations': 1 },
               {'inputs': [('PINA',0xFF)], 'iterations': 1 },
               {'inputs': [('PINA',0xFE)], 'iterations': 1 },
               {'inputs': [('PINA',0xFF)], 'iterations': 1 },
               {'inputs': [('PINA',0xFE)], 'iterations': 1 },
               {'inputs': [('PINA',0xFF)], 'iterations': 1 },
               {'inputs': [('PINA',0xFE)], 'iterations': 1 },
               {'inputs': [('PINA',0xFF)], 'iterations': 1 },
               {'inputs': [('PINA',0xFE)], 'iterations': 1 },
               {'inputs': [('PINA',0xFF)], 'iterations': 1 },

                 ],
    'expected': [('PORTB',0x01)],
    },






  #{'description': 'PressPA0  => PORTC: 0x08 ',
   # 'steps': [ {'inputs': [('PINA',0x00)], 'iterations': 2 },
    #            {'inputs': [('PINA',0x02)], 'iterations': 2 },
     #            {'inputs': [('PINA',0x02)], 'iterations': 2 },
      #            {'inputs': [('PINA',0x02)], 'iterations': 2 },
       #           {'inputs': [('PINA',0x02)], 'iterations': 2 },
        #         {'inputs': [('PINA',0x02)], 'iterations': 2 },
         #         {'inputs': [('PINA',0x02)], 'iterations': 2 },
          #       ],
  #  'expected': [('PORTC',0x06)],
   # },



    ]

    