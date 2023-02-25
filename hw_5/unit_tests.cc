#include <math.h>
#include <float.h>
#include <assert.h>
#include "utilities.h"
#include "gtest/gtest.h"
#include <vector>

using namespace std;

namespace {

    /***************Unit Tests for Typed Arrays*****************/

    /***************Sort By Magnitude*************************/
    TEST(Utilities, SortByMagnitude) {

        vector<double> m;

        for (int i=-2; i<2; i++) {
            m.push_back(i);
        }
        m.push_back(1);

        sort_by_magnitude(m);

        EXPECT_DOUBLE_EQ(m[0], 0);
        EXPECT_DOUBLE_EQ(m[1], -1);
        EXPECT_DOUBLE_EQ(m[2], 1);
        EXPECT_DOUBLE_EQ(m[3], 1);
        EXPECT_DOUBLE_EQ(m[4], -2);

    }
    
    /**********************Read & Write*******************************/
    TEST(UtilitiesTest, ReadAndWriteMatrixCsv) {

        TypedArray<TypedArray<double>> values_to_write;

        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                values_to_write.get(i).set(j,3*i+j);
            }
        }

        cout << values_to_write << "\n"; 

        write_matrix_csv(values_to_write,"test.csv");

        TypedArray<TypedArray<double>> values_read = read_matrix_csv("test.csv");

        EXPECT_EQ(values_read.size(), values_to_write.size());
        for (int i = 0; i < values_read.size(); i++) {
            EXPECT_EQ(values_read.get(i).size(), values_to_write.get(i).size());
            for (int j = 0; j < values_read.get(i).size(); j++) {
            EXPECT_DOUBLE_EQ(values_read.get(i).get(j), values_to_write.get(i).get(j));
            }
        }
    }

    /****************Occurence Map-Simple File***********************/
    TEST(OccurrenceMapTest, SimpleFile) {
        ofstream file("test.txt");
        file << "The test file to check the occurences";
        file.close();
        map<string, int> occurrence = occurrence_map("test.txt");
        for (auto const &pair: occurrence) {
            cout << "{" << pair.first << ": " << pair.second << "}\n";
        }
        EXPECT_EQ(occurrence["the"], 2);
        EXPECT_EQ(occurrence["test"], 1);
        EXPECT_EQ(occurrence["file"], 1);
        EXPECT_EQ(occurrence["to"], 1);
        EXPECT_EQ(occurrence["check"], 1);
        EXPECT_EQ(occurrence["occurences"], 1);
        EXPECT_EQ(occurrence.size(), 6);
    }

    /****************Occurence Map-Complex File***********************/
    TEST(OccurrenceMapTest, ComplexFile) {
        map<string, int> occurrence = occurrence_map("test_1.txt");
        for (auto const &pair: occurrence) {
            cout << "{" << pair.first << ": " << pair.second << "}\n";
        }
        EXPECT_EQ(occurrence["10xgenomics"], 1);
        EXPECT_EQ(occurrence["123"], 1);
        EXPECT_EQ(occurrence["a"], 3);
        EXPECT_EQ(occurrence["are"], 1);
        EXPECT_EQ(occurrence["as"], 2);
        EXPECT_EQ(occurrence["biotech"], 1);
        EXPECT_EQ(occurrence["blah"], 3);
        EXPECT_EQ(occurrence["constant"], 1);
        EXPECT_EQ(occurrence["don't"], 1);
        EXPECT_EQ(occurrence["done"], 1);
        EXPECT_EQ(occurrence["double"], 1);
        EXPECT_EQ(occurrence["famous"], 1);
        EXPECT_EQ(occurrence["george"], 1);
        EXPECT_EQ(occurrence["i"], 1);
        EXPECT_EQ(occurrence["i'm"], 1);
        EXPECT_EQ(occurrence["in"], 1);
        EXPECT_EQ(occurrence["is"], 4);
        EXPECT_EQ(occurrence["mallory's"], 1);
        EXPECT_EQ(occurrence["mind"], 1);
        EXPECT_EQ(occurrence["my"], 1);
        EXPECT_EQ(occurrence["nice"], 1);
        EXPECT_EQ(occurrence["number"], 1);
        EXPECT_EQ(occurrence["of"], 2);
        EXPECT_EQ(occurrence["quote"], 1);
        EXPECT_EQ(occurrence["quoted"], 1);
        EXPECT_EQ(occurrence["quotes"], 1);
        EXPECT_EQ(occurrence["rebellion"], 1);
        EXPECT_EQ(occurrence["saying"], 1);
        EXPECT_EQ(occurrence["sentence"], 1);
        EXPECT_EQ(occurrence["should"], 1);
        EXPECT_EQ(occurrence["so"], 1);
        EXPECT_EQ(occurrence["state"], 1);
        EXPECT_EQ(occurrence["strings"], 1);
        EXPECT_EQ(occurrence["think"], 1);
        EXPECT_EQ(occurrence["this"], 1);
        EXPECT_EQ(occurrence["use"], 1);
        EXPECT_EQ(occurrence["words"], 1);
        EXPECT_EQ(occurrence.size(), 37);
    }
}