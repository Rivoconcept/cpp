
#include "iterator.hpp"

int main() {
    // Test 1: Création et accès basique
    std::cout << "=== Test 1: Création et accès ===" << std::endl;
    Container<int> nums(3);
    nums[0] = 10;
    nums[1] = 20;
    nums[2] = 30;

    for (unsigned int i = 0; i < nums.size(); ++i) {
        std::cout << "nums[" << i << "] = " << nums[i] << std::endl;
    }
    std::cout << "Taille: " << nums.size() << std::endl;

    // Test 2: Itérateurs
    std::cout << "\n=== Test 2: Itérateurs ===" << std::endl;
    std::cout << "Parcours avec iterateurs: ";
    for (Container<int>::Iterator it = nums.begin(); it != nums.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Test 3: Opérateurs ++ et --
    std::cout << "\n=== Test 3: Opérateurs ++/-- ===" << std::endl;
    Container<int>::Iterator it = nums.begin();
    std::cout << "Début: " << *it << std::endl;
    ++it;
    std::cout << "Après ++: " << *it << std::endl;
    it--;
    std::cout << "Après --: " << *it << std::endl;

    // Test 4: Opérateurs + et -
    std::cout << "\n=== Test 4: Opérateurs +/- ===" << std::endl;
    Container<int>::Iterator it2 = nums.begin() + 2;
    std::cout << "begin() + 2: " << *it2 << std::endl;
    it2 = it2 - 1;
    std::cout << "Moins 1: " << *it2 << std::endl;

    // Test 5: push_back et pop_back
    std::cout << "\n=== Test 5: push_back/pop_back ===" << std::endl;
    nums.push_back(40);
    std::cout << "Après push_back(40): ";
    for (Container<int>::Iterator it3 = nums.begin(); it3 != nums.end(); ++it3) {
        std::cout << *it3 << " ";
    }
    std::cout << "\nTaille: " << nums.size() << std::endl;

    nums.pop_back();
    std::cout << "Après pop_back(): ";
    for (Container<int>::Iterator it4 = nums.begin(); it4 != nums.end(); ++it4) {
        std::cout << *it4 << " ";
    }
    std::cout << "\nTaille: " << nums.size() << std::endl;

    // Test 6: Copie
    std::cout << "\n=== Test 6: Copie ===" << std::endl;
    Container<int> nums2 = nums;
    std::cout << "Copie: ";
    for (Container<int>::Iterator it5 = nums2.begin(); it5 != nums2.end(); ++it5) {
        std::cout << *it5 << " ";
    }
    std::cout << std::endl;

    // Test 7: Comparaison d'itérateurs
    std::cout << "\n=== Test 7: Comparaisons ===" << std::endl;
    Container<int>::Iterator begin = nums.begin();
    Container<int>::Iterator end = nums.end();
    std::cout << "begin == begin: " << (begin == begin) << std::endl;
    std::cout << "begin != end: " << (begin != end) << std::endl;

    // Test 8: operator->
    std::cout << "\n=== Test 8: operator-> ===" << std::endl;
    Container<std::string> words(1);
    words[0] = "Bonjour";
    Container<std::string>::Iterator word_it = words.begin();
    std::cout << "Taille du premier mot: " << word_it->size() << std::endl;

    return 0;
}