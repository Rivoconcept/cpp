/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:37:35 by rhanitra          #+#    #+#             */
/*   Updated: 2025/06/10 17:37:36 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
    Data original;
    original.id = 42;
    original.name = "OpenAI";

    uintptr_t raw = Serializer::serialize(&original);
    Data* deserialized = Serializer::deserialize(raw);

    std::cout << "Original address:    " << &original << "\n";
    std::cout << "Deserialized address: " << deserialized << "\n";

    if (deserialized == &original)
        std::cout << "Success: Pointers match.\n";
    else
        std::cout << "Failure: Pointers do not match.\n";

    std::cout << "Deserialized Data: id = " << deserialized->id
              << ", name = " << deserialized->name << std::endl;

    return 0;
}

