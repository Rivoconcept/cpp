/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getFileContents.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:56:11 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/24 17:03:41 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getFileContents.hpp"

GetFileContents::GetFileContents(std::string filename) : _filename(filename.c_str()) {}

GetFileContents::~GetFileContents() {}

const std::string& GetFileContents::getFileName() const
{
    return (this->_filename);
}

const std::string& GetFileContents::getFileContents() const
{
    return (this->_lines);
}

void    GetFileContents::setFileName(std::string filename)
{
    this->_filename = filename.c_str();
}

const std::size_t& GetFileContents::getFileSize() const
{
    return (this->_fileSize);
}

void GetFileContents::setFileSize(std::size_t size)
{
    this->_fileSize = size;
}

void GetFileContents::setFileContents()
{
    std::ifstream ifs(_filename.c_str());
    if (!ifs)
    {
        throw std::runtime_error("Error: cannot open file '" + _filename + "'");
    }

    this->_lines = std::string();
    std::string line;
    
    while (std::getline(ifs, line))
    {
        this->_lines += line;
        if (!ifs.eof())
        {
            this->_lines += '\n';
        }
    }
    ifs.close();
}
