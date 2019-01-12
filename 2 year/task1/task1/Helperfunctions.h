#pragma once


bool name_sort(Brugada a, Brugada b)
{
    return a.get_brugader_name() < b.get_brugader_name();
}

bool data_sort(Material a,Material b)
{
    return a.get_data() < b.get_data();
}

int total_sum(deque<Material> mat)
{
    int s = 0;
    for (deque<Material>::iterator i = mat.begin(); i != mat.end(); i++)
    {
        s += i->get_price();
    }
    return s;
}
deque<Brugada> input_information(string file)
{
    deque<Brugada> arr;
    ifstream my_file;
    
    my_file.open(file);
    //
    if (!my_file.is_open())
    {
        throw "can not open file";
    }
    while (!my_file.eof())
    {
        Brugada brugada;
        brugada.input(my_file);
        arr.push_back(brugada);
    }
    my_file.close();
    return arr;
}


void task1(deque<Brugada> arr )
{
    
    ofstream file("/Users/Andriana/Desktop/dz_programming/2 year/task1/task1/result.txt", ios_base::out | ios_base::trunc);
    
    if (!file)
    {
        throw "can not open or create file ";
    }
    
    sort(arr.begin(), arr.end(), name_sort);
    
    file << " Sorted brudadas  : \n\n ";
    
    for (deque<Brugada>::iterator it = arr.begin(); it != arr.end(); it++)
    {
        
        it->output(file);
        it->output();
        
    }
    
    
}


//

void task2(deque<Brugada> arr)
{
    
    ofstream file("/Users/Andriana/Desktop/dz_programming/2 year/task1/task1/result1.txt", ios_base::out | ios_base::trunc);
    
    if (!file)
    {
        throw "can not open or create file ";
    }
    
    file << " Sorted by data od materials  : \n\n ";
    
    for (deque<Brugada>::iterator it = arr.begin(); it != arr.end(); it++)
    {
        file << "Number" << it->get_number() << endl;
        deque<Material>mat = it->get_materials();
        sort(mat.begin(), mat.end(), data_sort);
        for (deque<Material>::iterator it = mat.begin(); it != mat.end(); it++)
        {
            file << "Name:" << it->get_name() << endl;
            file << "volume:" << it->get_volume() << endl;
            file << "price:" << it->get_price() << endl;
            file << "data:" << it->get_data() << endl;
        }
        file << "total sum : " << total_sum(mat)<<endl;
    }
    
}
