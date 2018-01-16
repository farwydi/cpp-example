#pragma once

#include <string>
#include <iostream>
#include <fstream>

typedef struct
{
    unsigned int nFileId;
    unsigned int nPacketLength;
    char *pDataFile;
} TPacketHeader;

class DataTranslator
{
  public:
    DataTranslator(const std::string &my_file_name)
        : pFileData(nullptr), nPacketCount(0)
    {
        std::ifstream my_file(my_file_name, std::ifstream::binary);

        my_file.read(reinterpret_cast<char *>(&nPacketCount), sizeof(nPacketCount));
        pFileData = new TPacketHeader[nPacketCount];

        for (int i = 0; i < nPacketCount; i++)
        {
            TPacketHeader head;
            my_file.read(reinterpret_cast<char *>(&head.nFileId), sizeof(head.nFileId));
            my_file.read(reinterpret_cast<char *>(&head.nPacketLength), sizeof(head.nPacketLength));
            head.pDataFile = new char[head.nPacketLength];
            my_file.read(head.pDataFile, head.nPacketLength);
            pFileData[i] = head;
        }

        my_file.close();
    }
    ~DataTranslator()
    {
    }

    void Show()
    {
        std::cout << "packet_count: " << nPacketCount << std::endl;
        for (int i = 0; i < nPacketCount; i++)
        {
            std::cout << "=============================" << std::endl;
            std::cout << "Id: " << pFileData[i].nFileId << std::endl;
            std::cout << "Data: " << pFileData[i].pDataFile << std::endl;
        }
    }

  private:
    TPacketHeader *pFileData;

    unsigned int nPacketCount;
};
