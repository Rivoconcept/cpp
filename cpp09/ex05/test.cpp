#include "PmergeMe.hpp"

std::vector<int> PmergeMe::fordJohnsonVecSort(std::vector<int> inputMax)
{
    int n = static_cast<int>(inputMax.size());
    if (n <= 1)
    {
        return inputMax;
    }

    std::vector<std::pair<int, int> > pairs;
    int single = -1;

    for (int i = 0; i + 1 < n; i += 2)
    {
        if (inputMax[i] < inputMax[i + 1])
        {
            pairs.push_back(std::pair<int, int>(inputMax[i + 1], inputMax[i]));
        } else
        {
            pairs.push_back(std::pair<int, int>(inputMax[i], inputMax[i + 1]));
        }
    }

    if (n % 2 != 0)
    {
        single = inputMax[n - 1];
    }

    std::vector<int> maxS;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        maxS.push_back(pairs[i].first);
    }

    std::vector<int> sorted = fordJohnsonVecSort(maxS);
                        

    size_t size = sorted.empty() ? 0 : sorted.back() + 1;
    
    std::vector<int> tmp(size, 0);
    
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        if (it->first < static_cast<int>(tmp.size()))
        {
            tmp[it->first] = it->second;
        }
    }
    
    std::vector<int> Min;
    for (std::vector<int>::iterator it = sorted.begin(); it != sorted.end(); ++it)
    {
        if (*it < static_cast<int>(tmp.size()))
        {
            Min.push_back(tmp[*it]);
        }
        else
        {
            Min.push_back(0);
        }
    }

    if (!Min.empty())
    {
        sorted.insert(sorted.begin(), Min[0]); // Insérer y2 (apparié à x1)
        Min.erase(Min.begin());               // Supprimer y2
    }
    
    std::vector<size_t> jacobOrder = VecGenerateJacobsthal(Min.size());

    for_each(jacobOrder.begin(), jacobOrder.end(), displayArray);
    
    for (size_t i = 0; i < jacobOrder.size() && i < Min.size(); ++i) {
        size_t index = jacobOrder[i];
        int yi = Min[index]; // y_{index+2}
        // x_{index+2} est à la position index + 1 dans sorted après l'étape 4
        size_t xi_index = index + 1;
        if (xi_index >= sorted.size()) {
            continue; // Sécurité
        }
        // Recherche binaire de sorted.begin() jusqu'à xi_pos exclu
        std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.begin() + xi_index, yi);
        sorted.insert(pos, yi);
    }

    // Insérer le singleton, si présent
    if (single != -1) {
        std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), single);
        sorted.insert(pos, single);
    }

    return sorted;
}


for (size_t i = 0; i < jacobOrder.size() && i < MinJacobOrder.size(); ++i) {
            size_t index = jacobOrder[i];
            if (index >= Min.size() || index == 0) { // Ignorer index == 0 (Min[0] déjà inséré)
                continue;
            }
            // Trouver la position de xi dans sorted
            int xi = pairs[index - 1].first; // xi associé à yi (index - 1 car Min[0] est y1)
            std::vector<int>::iterator xi_pos = std::find(sorted.begin(), sorted.end(), xi);
            if (xi_pos == sorted.end()) {
                continue; // Sécurité : si xi n'est pas trouvé
            }
            // Recherche dichotomique de MinJacobOrder[i] dans sorted[0, xi_pos)
            std::vector<int>::iterator insert_pos = std::lower_bound(sorted.begin(), xi_pos, MinJacobOrder[i]);
            sorted.insert(insert_pos, MinJacobOrder[i]);
        }
