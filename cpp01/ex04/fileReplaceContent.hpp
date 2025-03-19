/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileReplaceContent.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:05:56 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/19 22:35:33 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACECONTENT_HPP
# define REPLACECONTENT_HPP

# include "getFileContents.hpp"

class ReplaceContent
{
	private:
		std::string 		_s1;
		std::string 		_s2;
		GetFileContents& 	_contents;
		
	public:
		ReplaceContent(std::string s1, std::string s2, GetFileContents& contents);
		~ReplaceContent();

		void replaceFileContent();
};

#endif

