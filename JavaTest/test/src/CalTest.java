import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.text.DateFormat;
import java.time.*;
import java.util.*;

/* 
 * 
 * 
 * 
*/
public class CalTest {
    
    public static int solution(String joinDt, String endDt, String[] holiDays) {

        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy/MM/dd");
        DateTimeFormatter holiDayFormater = DateTimeFormatter.ofPattern("MM/dd");

        LocalDate workStartDate = LocalDate.parse(joinDt.substring(0,10), formatter);
        LocalDate workEndDate = LocalDate.parse(endDt, formatter);

        Set<LocalDate> holiDaySet = new HashSet<>();
        
        for (int year = workStartDate.getYear(); year <= workEndDate.getYear(); year++) {

            for (String holiDay : holiDays) {   
                MonthDay monDate = MonthDay.parse(holiDay, holiDayFormater);
                LocalDate holiDate = LocalDate.of(year, monDate.getMonth(), monDate.getDayOfMonth());
                
                if (!holiDate.isAfter(workEndDate) && !holiDate.isBefore(workStartDate)) {
                    holiDaySet.add(holiDate);
                }
            }
        }
        
        
        int workPeriod = 0;
        LocalDate curDate = workStartDate;

        while(!curDate.isAfter(workEndDate)) {

            int weekVal = curDate.getDayOfWeek().getValue();

            if (weekVal != 6 && weekVal != 7 && !holiDaySet.contains(curDate)) {
                ++workPeriod;
            }

            curDate = curDate.plusDays(1);
        }
        
        return workPeriod;
    }
    

    public static void main(String[] args) {
        
        // String joinDt = "2023/11/21 THU";
        // String endDt = "2023/11/21";
        // String[] holiDays = {"12/23"};

        //String joinDt = "2024/01/29 MON";
        //String endDt = "2024/03/04";
        //String[] holiDays = {"02/09", "02/13", "03/01"};

        //int result = solution(joinDt, endDt, holiDays);

        //System.out.println(result);

        String joinDt = "2024/12/09";
        String endDt = "2024/12/10";
        
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy/MM/dd");

        LocalDate startDt = LocalDate.parse(joinDt, formatter);
        LocalDate endingDt = LocalDate.parse(endDt, formatter);

        System.out.println(startDt.getDayOfWeek().getValue());
        System.out.println(startDt.getDayOfMonth());

        System.out.println(startDt.isAfter(startDt));
        
        

    }

}


















// public static int solution(String joinDt, String resignDate, String[] holiDays) {

//     DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy/MM/dd");
//     DateTimeFormatter holidayFormatter = DateTimeFormatter.ofPattern("MM/dd");

//     LocalDate start = LocalDate.parse(joinDt.substring(0, 10), formatter);
//     LocalDate end = LocalDate.parse(resignDate, formatter);
    
//     Set<LocalDate> holidayDates = new HashSet<>();

//     for (int year = start.getYear(); year <= end.getYear(); year++) {

//         for (String holiday : holiDays) {
            
//             MonthDay monthDay = MonthDay.parse(holiday, holidayFormatter);
//             LocalDate holidayDate = LocalDate.of(year, monthDay.getMonth(), monthDay.getDayOfMonth());
            
//             if (!holidayDate.isBefore(start) && !holidayDate.isAfter(end)) {
//                 holidayDates.add(holidayDate);
//             }
//         }
//     }

//     int workingDays = 0;
//     LocalDate curDate = start;

//     while(!curDate.isAfter(end)) {
        
//         int weekVal = curDate.getDayOfWeek().getValue();
        
//         if (!(weekVal == 6 || weekVal == 7 || holidayDates.contains(curDate))) {
//             workingDays++;
//         }
        
//         curDate = curDate.plusDays(1);
//     }
    
//     return workingDays;
// }