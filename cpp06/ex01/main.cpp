/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:37:35 by rhanitra          #+#    #+#             */
/*   Updated: 2025/06/14 11:06:33 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
    {    Data data;
        data.id = 3;
        data.name = "School_42";

        uintptr_t raw = Serializer::serialize(&data);
        Data* deserialized = Serializer::deserialize(raw);

        std::cout << "data address:    " << &data << "\n";
        std::cout << "Deserialized address: " << deserialized << "\n";

        if (deserialized == &data)
            std::cout << "Success: Pointers match.\n";
        else
            std::cout << "Failure: Pointers do not match.\n";

        std::cout << "Deserialized Data: id = " << deserialized->id
                << ", name = " << deserialized->name << std::endl;
    }
    {
        std::cout << std::endl;
    
        Data data;
        uintptr_t raw = Serializer::serialize(&data);
        raw += 4;
        Data* deserialized = Serializer::deserialize(raw);

        std::cout << "data address:    " << &data << "\n";
        std::cout << "Deserialized address: " << deserialized << "\n";
        if (deserialized == &data)
            std::cout << "Success: Pointers match.\n";
        else
            std::cout << "Failure: Pointers do not match.\n";
            
    }

    return 0;
}

