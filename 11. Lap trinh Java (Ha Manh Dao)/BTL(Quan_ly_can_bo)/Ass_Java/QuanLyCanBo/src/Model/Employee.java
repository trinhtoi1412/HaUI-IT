/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Model;

import java.io.Serializable;

/**
 *
 * @author thinh
 */
public class Employee implements Serializable{
    private String Id;
    private String tenEP;
    private String tuoiEP;
    private String chucVuEP;

    public Employee() {
    }

    public Employee(String Id, String tenEP, String tuoiEP, String chucVuEP) {
        this.Id = Id;
        this.tenEP = tenEP;
        this.tuoiEP = tuoiEP;
        this.chucVuEP = chucVuEP;
    }

    public String getId() {
        return Id;
    }

    public void setId(String Id) {
        this.Id = Id;
    }

    public String gettenEP() {
        return tenEP;
    }

    public void settenEP(String tenEP) {
        this.tenEP = tenEP;
    }

    public String gettuoiEP() {
        return tuoiEP;
    }

    public void settuoiEP(String tuoiEP) {
        this.tuoiEP = tuoiEP;
    }

    public String getchucVuEP() {
        return chucVuEP;
    }

    public void setchucvuEP(String chucVuEP) {
        this.chucVuEP = chucVuEP;
    }
    
    
}
