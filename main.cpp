#include "music.h"
int main() {
	int value = 0;						
        int katalog_size = 0;				
	music *katalog = 0;										
	int x;	
	char file[str_length];	 			
        while(1){
        cout<<"Просмотр каталога 1\nДобавление музыки 2\nУдаление музыки 3\nСохранение данных 4\nЗагрузка данных 5\nПоиск музыки 6\nВыход 0\n";
        cout<<"\nВаш выбор: ";
        cin>>x;  
        switch (x)
        {
        case 1://просмотр каталога  
                cout<<"Каталог музыки\n\n";
                show_katalog(katalog, value);
                break;
       case 2://добавление музыки
	        cout<<"Добавление новой записи\n";
                value++;
                if (katalog_size <= value)
                {
                        katalog_size++;
                        katalog = (music*)realloc(katalog, sizeof(music) * katalog_size);
                }
                add_music(&katalog[value - 1]);
                cout<<"Запись добавлена\n\n";
                break;
        // удаление
        case 3:
                cout<<"Удаление записи\n\n";
                remove_entry(katalog, &value);
                break;
       // Сохранение данных
        case 4:
                cout<<"Имя файла для сохранения: ";
                cin>>file;
                save_music(katalog, value, file);
                break;
      // загрузка из файла
		case 5:
			delete katalog;
                        value = 0;
			katalog = load(katalog,&value);
			katalog_size = value;
			break;

		// поиск
		case 6:
               	podmenu(katalog, value);
                break;

		// выход
		case 0:
		        delete katalog;
			return 0;
                default:cout<<"Неправильный ввод\n";
        }
} 
} 
