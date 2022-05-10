#include<unistd.h>
#include<pthread.h>
#include<stdio.h>

// les prototypes des fonctions
void *function1(); // 1er thread(celui qui utilise la ressource)
void *function2(); // 2eme thread(celui qui utilise la ressource)

// les variables
pthread_mutex_t first_mutex, second_mutex; // les deux ressources

int main(){
    // initialiser les ressources
    pthread_mutex_init(&first_mutex, NULL);
    pthread_mutex_init(&second_mutex, NULL);

    // initialiser les threads
    pthread_t T1, T2;
    pthread_create(&T1, NULL, function1(), NULL);
    pthread_create(&T2, NULL, function2(), NULL);

    // joindre les deux threads
    pthread_join(T1, NULL);
    pthread_join(T2, NULL);

    printf("thread joined\n");
}

// definir les fonctions
void *function1(){
    printf("T1 essaie d'acceder à la ressource first_mutex");
    // liberer la premiere ressource
    pthread_mutex_lock(&first_mutex);
    // puisque la premiere ressource est libre,
    printf("T1 a accès à first_mutex\n");
    // ensuite on endort ce processus pour une seconde
    sleep(1);
    // pendant que le processus first_mutex est endormi, T1 essaye d'acceder à second_mutex
    printf("T1 essaie d'acceder à second_mutex");
    pthread_mutex_lock(&second_mutex);
    printf("T1 a accès à second_mutex\n");
}

void *function2(){
    printf("T2 essaie d'acceder à la ressource second_mutex");
    // liberer la premiere ressource
    pthread_mutex_lock(&second_mutex);
    // puisque la premiere ressource est libre,
    printf("T2 a accès à second_mutex\n");
    // ensuite on endort ce processus pour une seconde
    sleep(1);
    // pendant que le processus first_mutex est endormi, T1 essaye d'acceder à second_mutex
    printf("T2 essaie d'acceder à first_mutex");
    pthread_mutex_lock(&second_mutex);
    printf("T2 a accès à fisrt _mutex\n");
}





