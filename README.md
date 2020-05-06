# Proiect_2_final

Implementarea de baza a algoritmului se bazeaza pe impartirea suprafetei
in triunghiuri si parcurgerea individuala a acestor triunghiuri.

Primul pas este pozitionarea robotului intr-unul dintre colturile triunghiului
prin intermediul functiei init() din structura Robot.
Apoi, robotul parcurge triunghiul latura cu latura, micsorand de fiecare data
suprafata ramasa. Trecerea dintr-un colt in altul al suprafetei ramase se face
prin intermediul functiei next_corner din structura Robot. Variabilele
calculate in cadrul acestei functii sunt ilustrate in imaginea triunghi.png

Fisierul de input trebuie sa contina coordonatele patrulaterului si raza robotului.

Format-ul fisierului de input:

x1 y1
x2 y2
x3 y3
x4 y4
r

Output-ul reprezinta o lista de coordonate care reprezinta pozitiile succesive
prin care trece robotul pentru a acoperi suprafata.
