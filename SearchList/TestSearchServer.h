#pragma once

/*
void UnitTestingSeaarchServer()
{
    try {
        SearchServer search_server{ "и в на"s };


        ASSERT(search_server.AddDocument(0, "белый кот и модный ошейник"s, DocumentStatus::ACTUAL, { 8, -3 }).value() == 0);
        ASSERT(search_server.AddDocument(1, "пушистый кот пушистый хвост"s, DocumentStatus::ACTUAL, { 7, 2, 7 }).value() == 0);
        ASSERT(search_server.AddDocument(2, "ухоженный пёс выразительные глаза"s, DocumentStatus::ACTUAL, { 5, -12, 2, 1 }).value() == 0);
        ASSERT(search_server.AddDocument(3, "ухоженный скворец евгений"s, DocumentStatus::BANNED, { 9 }).value() == 0);



        cout << "ACTUAL by default:"s << endl;
        auto st = search_server.FindTopDocuments("пушистый ухоженный кот"s);
        if (st.has_value()) {
            for (const Document& document : st.value()) {
                PrintDocument(document);
            }
        }

        cout << "BANNED:"s << endl;
        auto st2 = search_server.FindTopDocuments("пушистый ухоженный кот"s, DocumentStatus::BANNED);
        if (st2.has_value()) {
            for (const Document& document : st2.value()) {
                PrintDocument(document);
            }
        }

        cout << "Even ids:"s << endl;
        auto st3 = search_server.FindTopDocuments("пушистый ухоженный кот"s, [](int document_id, DocumentStatus status, int rating) { return document_id % 2 == 0; });
        if (st3.has_value()) {
            for (const Document& document : st3.value()) {
                PrintDocument(document);
            }
        }
    }

    catch (const domain_error& e) {
        cout << "error: "s << e.what() << endl;
    }
    catch (const invalid_argument& e) {
        cout << "error: "s << e.what() << endl;
    }
    catch (...) {
        cout << "not find eror" << endl;
    }
    std::cout << "TEST VALIED" << std::endl;
}

*/

void Test_2() {
    setlocale(LC_ALL, "russian");


    SortedStack<int> stack;
    vector<int> values{ 10, 20, 30, 40, 50 };

    // заполняем стек и проверяем, что сортировка сохраняется после каждой вставки
    for (int i = 0; i < 5; ++i) {
        cout << "Вставляемый элемент = "s << values[i] << endl;
        stack.Push(values[i]);
        stack.Print();
    }

    /*
    SearchServer search_server("and in at"s);
    RequestQueue request_queue(search_server);

    search_server.AddDocument(1, "curly cat curly tail"s, DocumentStatus::ACTUAL, { 7, 2, 7 });
    search_server.AddDocument(2, "curly dog and fancy collar"s, DocumentStatus::ACTUAL, { 1, 2, 3 });
    search_server.AddDocument(3, "big cat fancy collar "s, DocumentStatus::ACTUAL, { 1, 2, 8 });
    search_server.AddDocument(4, "big dog sparrow Eugene"s, DocumentStatus::ACTUAL, { 1, 3, 2 });
    search_server.AddDocument(5, "big dog sparrow Vasiliy"s, DocumentStatus::ACTUAL, { 1, 1, 1 });

    // 1439 запросов с нулевым результатом
    for (int i = 0; i < 1439; ++i) {
        request_queue.AddFindRequest("empty request"s);
    }
    // все еще 1439 запросов с нулевым результатом
    request_queue.AddFindRequest("curly dog"s);
    // новые сутки, первый запрос удален, 1438 запросов с нулевым результатом
    request_queue.AddFindRequest("big collar"s);
    // первый запрос удален, 1437 запросов с нулевым результатом
    request_queue.AddFindRequest("sparrow"s);
    cout << "Total empty requests: "s << request_queue.GetNoResultRequests() << endl;
    */
}