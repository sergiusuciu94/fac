Sa se implementeze in C o pereche de programe client/server care comunica prin socket-uri TCP/IP pentru rezolvarea urmatoarelor probleme:

* Un client trimite unui server un sir de numere. Serverul va returna clientului suma numerelor primite.
* Un client trimite unui server un sir de caractere. Serverul va returna clientului numarul de caractere spatiu din sir.
* Un client trimite unui server un sir de caractere. Serverul va returna clientului acest sir oglindit (caracterele sirului in ordine inversa).
* Un client trimite unui server doua siruri de caractere ordonate. Serverul va interclasa cele doua siruri si va returna clientului sirul rezultat interclasat.
* Un client trimite unui server un numar. Serverul va returna clientului sirul divizorilor acestui numar.
* Un client trimite unui server un sir de caractere si un caracter. Serverul va returna clientului toate pozitiile pe care caracterul primit se regaseste in sir.
* Un client trimite unui server un sir de caractere si doua numere (fie acestea s, i, l). Serverul va returna clientului subsirul de lungime l a lui s care incepe la pozitia i.
* Un client trimite unui server doua siruri de numere. Serverul va returna clientului sirul de numere comune celor doua siruri primite.
* Un client trimite unui server doua siruri de numere. Serverul va returna clientului sirul de numere care se regaseste in primul sir dar nu se regasesc in al doilea.
* Un client trimite unui server doua siruri de caractere. Serverul ii raspunde clientului cu caracterul care se regaseste de cele mai multe ori pe pozitii identice in cele doua siruri si cu numarul de aparitii ale acestui caracter.

Odata cu rezolvarea acestor probleme, studentii se vor familiariza cu utilizarea comenzilor strace si ltrace.