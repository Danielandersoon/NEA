import sqlite3

conect = sqlite3.connect(game.db)
cursor = conect.cursor()

cursor.execute('''CREATE TABLE IF NOT EXISTS table
                    (one, two, three, four)''')

conect.commit()
conect.close()
