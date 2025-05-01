/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:58:47 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/01 11:09:49 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
    private:
        Brain* _brain;

    public:
        Cat();
        Cat(const Cat& cat);
        Cat& operator=(const Cat& cat);
        ~Cat();

        void makeSound() const;

        const std::string& getBrainIdea(int index) const;
        void setBrainIdea(int index, const std::string& idea);

};

#endif