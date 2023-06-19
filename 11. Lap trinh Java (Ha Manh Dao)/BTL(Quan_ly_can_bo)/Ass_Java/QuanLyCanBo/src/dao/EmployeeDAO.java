package dao;

import Model.Employee;
import java.util.ArrayList;
import javax.swing.table.AbstractTableModel;

public class EmployeeDAO extends AbstractTableModel{
    private String name[] ={"Mã nhân viên","Tên nhân viên","Tuổi","Chức vụ"};
    private Class className[] ={Integer.class,String.class,String.class,String.class};
    private ArrayList<Employee> dsEP = new ArrayList<>();
    
    public EmployeeDAO(ArrayList<Employee> ep){
        this.dsEP = ep;
    }
    
    @Override
    public int getRowCount() {
        return dsEP.size();
    }

    @Override
    public int getColumnCount() {
        return className.length;
    }

    @Override
    public Object getValueAt(int rowIndex, int columnIndex) {
        switch (columnIndex) {
            case 0:
                return dsEP.get(rowIndex).getId();
            case 1:
                return dsEP.get(rowIndex).gettenEP();
            case 2:
                return dsEP.get(rowIndex).gettuoiEP();
            case 3:
                return dsEP.get(rowIndex).getchucVuEP();
            default:
                throw new AssertionError();
        }
    }

    @Override
    public Class<?> getColumnClass(int columnIndex) {
        return className[columnIndex];
    }

    @Override
    public String getColumnName(int column) {
        return name[column];
    }
    
    
}
