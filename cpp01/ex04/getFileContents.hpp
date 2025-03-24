/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getFileContents.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:05:56 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/24 17:29:42 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILECONTENTS_HPP
# define FILECONTENTS_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>

class GetFileContents
{
	private:
		std::string 	_filename;
		std::size_t		_fileSize;
		std::string 	_lines;

	public:
		GetFileContents(std::string filename);
		~GetFileContents();

		const std::string& getFileName() const;
		void setFileName(std::string argv);

		const std::size_t& getFileSize() const;
		void setFileSize(std::size_t size);

		const std::string& getFileContents() const;
		void setFileContents();
};

#endif
