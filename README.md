# deadlock

ecrire un programme en c qui simule l'attente circulaire de l'interblocage des processus

programme à utiliser sur linux

avant de lancer le programme, il faut installer la libraire <pthread.h> en faisant :
$ sudo apt update
$ sudo apt install libpthread-stubs0-dev

la commande pour lancer dans le terminal est : 
$ gcc deadlock.c -o deadlock -pthread
$ ./deadlock
