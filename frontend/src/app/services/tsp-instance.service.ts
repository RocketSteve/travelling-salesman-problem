import {Injectable} from '@angular/core';
import {Point} from "../components/graph/point";
import {Subject} from "rxjs";

@Injectable({
  providedIn: 'root'
})
export class TspInstanceService {

  public points: Subject<Point[]> = new Subject<Point[]>();

  constructor() {
  }

  getTspInstance(instance: string) {
    const lines = instance.split("\n");
    const numberOfPoints = parseInt(lines[0]);
    if (numberOfPoints > 0) {
      const points: Point[] = [];
      for (let i = 1; i < lines.length; i++) {
        if (lines[i].length === 0) continue;
        const line = lines[i].split(" ");
        points.push({x: parseInt(line[0]), y: parseInt(line[1])});
      }
      this.points.next(points);
    }
  }

  checkValidTspInstance(instance: string): boolean {
    const lines = instance.split("\n");
    if (lines.length == 0) return false;
    const numberOfPoints = parseInt(lines[0]);
    if (numberOfPoints > 0) {
      for (let i = 1; i < lines.length; i++) {
        if (lines[i].length === 0) continue;
        const line = lines[i].split(" ");
        if (line.length !== 2) return false;
        if (isNaN(parseInt(line[0])) || isNaN(parseInt(line[1]))) return false;
      }
      return true;
    }
    return false;
  }
}
