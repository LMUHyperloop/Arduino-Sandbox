# BEFORE YOU EXECUTE, 'pip3 install PyQt5'


import sys      #IMPORT STATEMENTS
from PyQt5.QtWidgets import QApplication, QWidget

if __name__ == '__main__':

    app = QApplication(sys.argv)    #Creates application window / Obj

    w = QWidget()       #Default constructor for a QWidget
    w.resize(250, 150)  #Resizes widget to a specific size
    w.move(300, 300)    #Opens it in a certain area on screen
    w.setWindowTitle('Simple')
    w.show()            #Displays widget on screen. Created in mem first

    sys.exit(app.exec_())
