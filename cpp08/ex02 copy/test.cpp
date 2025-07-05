 {
        std::cout << "Testing iterator (forward):" << std::endl;
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }

    {
        const MutantStack<int>& constMstack = mstack;
        std::cout << "\nTesting const_iterator (forward, read-only):" << std::endl;
        MutantStack<int>::const_iterator cit = constMstack.begin();
        MutantStack<int>::const_iterator cite = constMstack.end();

        while (cit != cite)
        {
            std::cout << *cit << std::endl;
            ++cit;
        }
    }

    {
        std::cout << "\nTesting reverse_iterator (backward):" << std::endl;
        MutantStack<int>::reverse_iterator rit = mstack.rbegin();
        MutantStack<int>::reverse_iterator rite = mstack.rend();

        while (rit != rite)
        {
            std::cout << *rit << std::endl;
            ++rit;
        }
    }

    {
        const MutantStack<int>& constMstack = mstack;
        std::cout << "\nTesting const_reverse_iterator (backward, read-only):" << std::endl;
        MutantStack<int>::const_reverse_iterator crit = constMstack.rbegin();
        MutantStack<int>::const_reverse_iterator crite = constMstack.rend();

        while (crit != crite)
        {
            std::cout << *crit << std::endl;
            ++crit;
        }
    }


    {
        std::cout << "\nTesting MutantStack with std::list:" << std::endl;
        MutantStack<int, std::list<int>> listStack;

        listStack.push(100);
        listStack.push(200);
        listStack.push(300);

        for (MutantStack<int, std::list<int>>::iterator it = listStack.begin(); it != listStack.end(); ++it)
        {
            std::cout << *it << std::endl;
        }
    }