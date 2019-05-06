# C8051F930_Peripherique

* Microcontrôleur: C8051F930

* Langage utilisé: C, Assembleur

* Logiciel utilisé: Simplicity

* Résumé des principaux objectifs :

1. Ordonnanceur et Scheduler 

    •	Le programme du Microcontrôleur est scindé des tâches (processus/ threads) et l'ordonnanceur pilote l'exécution de chacune des tâches.

    •	Réaliser par un Timer qui sert de base de temps pour une interruption basse priorité.

2. Watchdog-Sécurité : En fonctionnement normal le comptage du Watchdog est régulièrement relancé à partir de sa valeur initiale.

3. Communication avec le Clavier

    •	Scrutation d'un périphérique (Clavier) dans l'ordonnanceur.

    •	Scinder des tâches pour des raisons fonctionnelles et temporelles.

    •	Créer une tâche de lecture d'un périphérique qui elle-même déclenchera des actions dans autres tâches.

4. Communication avec le LCD 16x2

    •	Scrutation d'un périphérique (LCD) dans l'ordonnanceur.

    •	Scinder des tâches pour des raisons fonctionnelles et temporelles.

    •	Créer une tâche de lecture d'un périphérique qui elle-même déclenchera des actions dans autres tâches.

5. Communication avec Ibutton

    •	Scrutation d'un périphérique (Ibutton) dans l'ordonnanceur.

    •	Scinder des tâches pour des raisons fonctionnelles et temporelles.

    •	Créer une tâche de lecture d'un périphérique qui elle-même déclenchera des actions dans autres tâches.

6. Communication avec des périphériques externes par la liaison UART 

    •	Protocole de lecture de l'identifiant unique de 8 octets.

    •	Protocole de lecture/ écriture sur l'I/O du 1 -Wire bus.

