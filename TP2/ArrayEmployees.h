
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} Employee;


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in 1 in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param size int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Okay
 */
int initEmployee(Employee* list, int size);
/** \brief look for a free place in the array
 * \param list Employee*
 * \param size int
 * \return return -1 if Error - the free place of the array
 */
int EmployeeFree(Employee *list,int size);
/** \brief Remove a Employee by Id (put isEmpty Flag in 0)
 * \param list Employee*
 * \param size int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Okay
 *
 */
int removeEmployee(Employee* list, int size, int id);
/** \brief print the content of employees array
 * \param list Employee*
 * \param size int
 * \return void return
 *
 */
void printEmployees(Employee* list, int size);
/** \brief find an Employee by Id en returns the index position in array.
 * \param list Employee*
 * \param size int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 */
int findEmployeeById(Employee* list, int size,int id);
/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param size int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Okay*/
int addEmployee(Employee* list, int size, int id, char name[],char lastName[],float salary,int sector);
/** \brief increase the id by 1 for each element in the array
 * \param list Employee*
 * \param size int
 * \return return void
 */
int incrementalID(Employee *list,int size);
/** \brief modify an employee of the array
 * \param list Employee*
 * \param size int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return return int
 */
int modifyEmployee(Employee* list,int size,int id, char name[],char lastName[],float salary,int sector);
/** \brief calculates the average of all employees and the total
 * \param list Employee*
 * \param size int
 * \return void return
 */
void averageEmployees(Employee* list,int size);
/** \brief Sort the elements in the array of employees
 * \param list Employee*
 * \param size int
 * \param order int [1] indicate UP
 * \return void return
 *
 */
void sortEmployees(Employee* list, int size,int order);


