import java.time.LocalDate;
import java.time.MonthDay;
import java.time.format.DateTimeFormatter;
import java.util.HashSet;
import java.util.Set;

public class WorkDaysCalculator {

    public static void main(String[] args) {
        String joinDt = "2019/12/01 SUN";
        String resignDate = "2019/12/31";
        String[] holidays = {"01/02", "12/24"};

        int workingDays = calculateWorkingDays(joinDt, resignDate, holidays);
        System.out.println("Total working days: " + workingDays);
    }
    
    public static int calculateWorkingDays(String joinDt, String resignDate, String[] holidays) {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy/MM/dd");
        DateTimeFormatter holidayFormatter = DateTimeFormatter.ofPattern("MM/dd");

        LocalDate start = LocalDate.parse(joinDt.substring(0, 10), formatter);
        LocalDate end = LocalDate.parse(resignDate, formatter);

        Set<LocalDate> holidayDates = new HashSet<>();
        
        for (int year = start.getYear(); year <= end.getYear(); year++) {
            for (String holiday : holidays) {
                MonthDay monthDay = MonthDay.parse(holiday, holidayFormatter);
                LocalDate holidayDate = LocalDate.of(year, monthDay.getMonth(), monthDay.getDayOfMonth());
                if (!holidayDate.isBefore(start) && !holidayDate.isAfter(end)) {
                    holidayDates.add(holidayDate);
                }
            }
        }

        int workingDays = 0;
        LocalDate current = start;

        while (!current.isAfter(end)) {
            if (!(current.getDayOfWeek().getValue() == 6 || current.getDayOfWeek().getValue() == 7 || holidayDates.contains(current))) {
                workingDays++;
            }
            current = current.plusDays(1);
        }

        return workingDays;
    }
}