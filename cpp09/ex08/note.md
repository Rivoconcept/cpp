./PmergeMe 81 103 5 23 7 18 56 73 42

1. Regrouper les éléments de X en [n / 2] paires d'éléments, arbitrairement, laissant un élément non apparié s'il y a un nombre impair d'éléments.
2. Effectuer [n / 2] comparaisons, une par paire, pour déterminer le plus grand des deux éléments de chaque paire (déterminer le maximum).
3. Trier récursivement (avec un tri par fusion-insertion) les [n / 2] plus grands éléments de chaque paire, créant une séquence triée  S des éléments d’entrée, 
par ordre croissant.
4. Insérer au début de S l'élément qui a été apparié au premier et au plus petit élément de  S.
5. Insérer le reste des [n / 2] - 1 éléments de X ∖S dans S, un à la fois, avec un ordre d'insertion spécialement choisi décrit ci-dessous. 
Utiliser la recherche dichotomique dans les sous-séquences de S (comme décrit ci-dessous) pour déterminer la position à laquelle 
chaque élément doit être inséré.
Cet algorithme est conçu pour tirer parti du fait que les recherches dichotomiques utilisées pour insérer des éléments dans S
{\displaystyle S} sont les plus efficaces (du point de vue de l'analyse au pire cas) lorsque la longueur de la sous-séquence 
recherchée est inférieure à une puissance de deux. En effet, pour ces longueurs, tous les résultats de la recherche utilisent 
le même nombre de comparaisons les uns que les autres[1]. Pour choisir un ordre d'insertion qui produit ces longueurs, 
prenons la séquence triée  après l'étape 4 du plan ci-dessus (avant d'insérer les éléments restants). Soit xi le 
i-ème élément de cette séquence triée. Ainsi on obtient, S =(x1,x2,x3,…), où chaque élément xi avec i ≥ 3 est associé 
à un élément yi < xi qui n'a pas encore été inséré. (y1 et y2 n'existent pas car x1 et x2 ont été jumelés les uns aux autres.)
Si n est impair, l'élément non apparié restant doit également être numéroté comme un yi avec i plus grand que les index des éléments
appariés. Ensuite, on peut étendre la dernière étape du plan ci-dessus aux étapes suivantes[1],[2],[3],[4]:

Partitionner les éléments non insérés yi en groupes avec des index contigus. Il y a deux éléments y3 et y4 dans le premier groupe,
et les sommes des tailles de tous les deux groupes adjacents forment une séquence de puissances de deux. Ainsi, les tailles 
des groupes sont : 2, 2, 6, 10, 22, 42...

Classer les éléments non insérés par groupes (des index plus petits vers des index plus grands), mais au sein de chaque groupe,
classez-les d'index plus grands vers des index plus petits. Ainsi, la commande devient  y4, y3,y6, y5, y12, y11, y10, y9, y8, y7, y22, y21 …
Utilisez cet ordre pour insérer les éléments yi dans S. Pour chaque élément yi, utilisez une recherche dichotomique à partir du début de 
S jusqu'à xi exclu afin de déterminer où insérer yi.

81 103 5 23 7 18 56 73 42 u=42

103 23  18  73                      5    7   18  23 56 73  103
81  5   7   56

103 73                              18  23  73  103
23  18

103                                 73  103
73




    std::vector<int> maxSorted = fordJohnsonVecSort(maxS);
   
    size_t sizeMapMax = MaxSorted.empty() ? 0 : static_cast<size_t>(_sizeTab + 1);
    unsigned int mapMax[sizeMapMax];
    
    size_t size = MaxSorted.empty() ? 0 : static_cast<unsigned int>(MaxSorted.back()) + 1;
    unsigned int* mapMin = new unsigned int[size];

    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
    {
        mapMax[it->second] = it->first;
        mapMin[it->first] = it->second;
    }

    _sortedVec = MaxSorted;

    for_each(MaxSorted.begin(), MaxSorted.end(), displayArray);
    std::cout << std::endl;
    
    if (!minX.empty())
    {
        _sortedVec.insert(_sortedVec.begin(), mapMin[MaxSorted[0]]);
    }
    (void)mapMax;

    std::vector<size_t> jacobG = VecgenerateJacobsthalGroup(minX.size());

    size_t i = 0;
    size_t limit = 0;

    for (size_t j = 0; j < jacobG.size(); j++)
    {
        size_t index = jacobG[j] - 1;
        
        if (index >= MaxSorted.size())
        {
            index = MaxSorted.size() - 1;
        }
        while (index != limit && i < minX.size() )
        {      
            if (index == 0)
                break;
            size_t max_pos = std::min(_sortedVec.size(), index + i + 1);
            std::vector<int>::iterator xi_pos = _sortedVec.begin() + max_pos;
            
            std::cout <<  "  i: " << i << "    index: " << index  << "    limit: " << limit << "    Min: " << MaxSorted[index] << std::endl;
            int to_insert = mapMin[MaxSorted[index]];

            std::vector<int>::iterator insert_pos = std::lower_bound(_sortedVec.begin(), xi_pos, to_insert);
            _sortedVec.insert(insert_pos, to_insert);
            
            i++;
            index--;
        }
        limit = jacobG[j] - 1;

    }

    if (_single != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(_sortedVec.begin(), _sortedVec.end(), _single);
        _sortedVec.insert(pos, _single);
    }
    
    delete[] mapMin;