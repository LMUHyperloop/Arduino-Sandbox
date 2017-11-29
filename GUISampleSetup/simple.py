# BEFORE YOU EXECUTE, 'pip3 install PyQt5'
# To run, type 'python3 simple.py' within your project directory

import sys      #IMPORT STATEMENTS
from PyQt5.QtWidgets import QApplication, QWidget

if __name__ == '__main__':

    app = QApplication(sys.argv)    #Creates application window / Obj

    w = QWidget()       #Default constructor for a QWidget
    w.resize(250, 300)  #Resizes widget to a specific size
    w.move(1100, 400)    #Opens at certain area (right, down)
    w.setWindowTitle('Simple')
    w.show()            #Displays widget on screen. Created in mem first

    sys.exit(app.exec_())
