/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileReplaceContent.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:05:56 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/19 19:40:57 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACECONTENT_HPP
# define FILEREPLACECONTENT_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <vector>
# include <cstdlib>
# include "getFileContents.hpp"

class ReplaceContent
{
	private:
		std::string _s1;
		std::string _s2;

	public:
		explicit ReplaceContent(const std::string& s1, const std::string& s2);
		~ReplaceContent();

		const std::string& getS1() const;
		const std::string& getS2() const;
		void replaceFileContent(const GetFileContents& contents, const std::string& filename);
};

#endif

