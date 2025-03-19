/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getFileContents.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:05:56 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/19 19:45:08 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILECONTENTS_HPP
# define FILECONTENTS_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <vector>
# include <cstdlib>

class GetFileContents
{
	private:
		std::string _filename;
		std::vector<std::string> _lines;

	public:
		explicit GetFileContents(const std::string& filename);
		~GetFileContents();

		const std::string& getFileName() const;
		const std::vector<std::string>& getFileContents() const;
		void setFileContents();
};

#endif
