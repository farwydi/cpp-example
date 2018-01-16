#include "DataTranslator.h"

int main()
{
    std::ofstream test("test.data", std::ofstream::binary);
    unsigned int count_packet = 256;

    test.write(reinterpret_cast<const char *>(&count_packet), sizeof(count_packet));

    for (auto i = 0; i < count_packet; i++)
    {
        TPacketHeader head;
        head.nFileId = i;
        head.nPacketLength = rand() % 100 + 1;
        head.pDataFile = new char[head.nPacketLength];

        for (auto n = 0; n < head.nPacketLength - 1; n++)
        {
            head.pDataFile[n] = 'a' + rand() % 26;
        }

        head.pDataFile[head.nPacketLength] = '\n';

        test.write(reinterpret_cast<const char *>(&head.nFileId), sizeof(head.nFileId));
        test.write(reinterpret_cast<const char *>(&head.nPacketLength), sizeof(head.nPacketLength));
        test.write(head.pDataFile, head.nPacketLength);
    }

    test.close();

    DataTranslator cl("test.data");
    cl.Show();
    return 0;
}
