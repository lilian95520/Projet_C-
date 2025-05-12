# Simulateur de Combat Pokémon (C++)

Petit projet de simulation de combats Pokémon en C++, basé sur la programmation orientée objet et le chargement de données depuis des fichiers CSV.

## Structure du projet
/
├─ src/ # Code source C++
│ ├─ main.cpp
│ ├─ Combat.h/.cpp
│ ├─ Pokemon.h/.cpp
│ ├─ Type.h/.cpp
│ ├─ Entraineur.h/.cpp
│ ├─ Joueur.h/.cpp
│ ├─ LeaderGym.h/.cpp
│ ├─ MaitrePokemon.h/.cpp
│ ├─ SimulationJeu.h/.cpp
│ └─ CSVLoader.h/.cpp
└─ data/ # Fichiers CSV de données
├─ types.csv
├─ pokemon.csv
├─ joueur.csv
├─ leaders.csv
└─ maitres.csv

## Compilation
```bash
g++ src/*.cpp -o lancer
.\lancer
```

