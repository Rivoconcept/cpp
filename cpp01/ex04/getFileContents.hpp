/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getFileContents.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:05:56 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/19 21:47:20 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILECONTENTS_HPP
# define FILECONTENTS_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>
# include <vector>

class GetFileContents
{
	private:
		std::string 				_filename;
		std::vector<std::string> 	_lines;

	public:
		GetFileContents(std::string filename);
		~GetFileContents();

		const std::string& getFileName() const;
		void setFileName(std::string argv);

		const std::vector<std::string>& getFileContents() const;
		void setFileContents();
};

#endif
